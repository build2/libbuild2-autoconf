#include <libbuild2/autoconf/init.hxx>

#include <algorithm> // sort()

#include <libbuild2/scope.hxx>
#include <libbuild2/variable.hxx>
#include <libbuild2/filesystem.hxx> // exists(), dir_iterator(), etc
#include <libbuild2/diagnostics.hxx>

#include <libbuild2/autoconf/rule.hxx>
#include <libbuild2/autoconf/module.hxx>

using namespace std;

namespace build2
{
  namespace autoconf
  {
    static project_checks
    load_project_checks (tracer&, const scope&, bool, const location&);

    //-
    // The `autoconf` module.
    //-
    bool
    init (scope& rs,
          scope& bs,
          const location& l,
          bool first,
          bool,
          module_init_extra& extra)
    {
      tracer trace ("autoconf::init");
      l5 ([&]{trace << "for " << bs;});

      if (first)
      {
        context& ctx (rs.ctx);

        // Load in.base (in.* variables, in{} target type).
        //
        load_module (rs, rs, "in.base", l);

        // Enter variables.
        //
        {
          // All the variables we enter are qualified so go straight for the
          // public variable pool.
          //
          auto& vp (rs.var_pool (true /* public */));

          // Configuration file flavor. Valid values are `autoconf` (default),
          // `cmake`, and `meson`.
          //
          vp.insert<string> ("autoconf.flavor");

          // Catalog checks prefix.
          //
          vp.insert<string> ("autoconf.prefix");

          // Substitution map (an alias for in.substitutions).
          //
          vp.insert_alias (*vp.find ("in.substitutions"),
                           "autoconf.substitutions");

          // Alias map. The key is the new name and the value is the aliased
          // (old) name.
          //
          // Note that this map is only consulted when resolving build-in
          // checks and the names should include the prefix, if any.
          //
          vp.insert<map<string, string>> ("autoconf.aliases");
        }

        // Load project-specific checks from build/autoconf/.
        //
        // If we are preparing a source distribution, then enter them as
        // targets so that they are automatically included.
        //
        project_checks pcs (
          load_project_checks (
            trace, rs, ctx.current_mif->id == dist_id, l));

        module& m (extra.set_module (new module (move (pcs))));

        // Register the rule.
        //
        // @@ TODO: this will be ambiguous, for example, version.in rule. Note
        //    also that if we register it for cc{}, then it will always take
        //    precedence over version.in, which is probably something we don't
        //    want. In fact, we would have liked it to be of lower precedence
        //    since version.in will only match if there is dependency on
        //    manifest.
        //
        rs.insert_rule<file> (perform_update_id,   "autoconf.in", m.rule);
        rs.insert_rule<file> (perform_clean_id,    "autoconf.in", m.rule);
        rs.insert_rule<file> (configure_update_id, "autoconf.in", m.rule);
      }

      return true;
    }

    static const dir_path checks_dir (dir_path ("autoconf") /= "checks");

    static project_checks
    load_project_checks (tracer& trace,
                         const scope& rs,
                         bool enter,
                         const location& loc)
    {
      dir_path d (rs.src_path () / rs.root_extra->build_dir / checks_dir);

      if (!exists (d))
        return {};

      auto df = make_diag_frame (
        [&loc, &d] (const diag_record& dr)
        {
          dr << info (loc) << "while loading project checks from " << d;
        });

      context& ctx (rs.ctx);

      try
      {
        project_checks pcs;

        path f (d); // Reuse to avoid allocations.
        for (const dir_entry& e:
               dir_iterator (d, dir_iterator::detect_dangling))
        {
          switch (e.type ())
          {
          case entry_type::regular:
            {
              const path& fn (e.path ());

              // Ignore everything except .h files.
              //
              // Wouldn't it be better to issue a warning or even an error?
              // Perhaps, but on the other hand, one may want to keep a README
              // or some such next to the checks, which seems reasonable.
              //
              if (icasecmp (fn.extension_cstring (), "h") != 0)
                break;

              f /= fn;

              l6 ([&]{trace << "loading " << f;});

              location loc (f, 0, 0);

              string v;
              try
              {
                ifdstream ifs (f, ifdstream::badbit);
                if (eof (getline (ifs, v, '\0')))
                  fail (loc) << "empty file";
              }
              catch (const io_error& e)
              {
                fail << "unable to read from " << f << ": " << e;
              }

              // The below parsing code is quite hairy because we try hard not
              // to make unnecessary copies.
              //
              // See the ad hoc rule in the buildfile for details on the
              // file format.
              //
              project_check pc;

              // Note: observe blank lines.
              //
              optional<size_t> p; // Start of comment/blank block.
              size_t b (0), e (0);
              for (size_t m (0), n (v.size ());
                   next_word (v, n, b, e, m, '\n', '\r'), b != n;)
              {
#if 0
                // Treat consecutive \r\n (CRLF) as if they were a single
                // delimiter (could be useful for something later, for
                // example, keeping track of line numbers).
                //
                if (b != 0 && v[b - 1] == '\r' &&
                    e != n && v[e] == '\n'     &&
                    m != 2)
                  continue;
#endif

                // First line should be the special comment in the form:
                //
                // // <NAME> [<MODIFIER>] [:<BASE>...]
                //
                // Note that our parsing is made to match the regex in
                // buildfile.
                //
                if (b == 0)
                {
                  if (e < 3 || v[0] != '/' || v[1] != '/' || v[2] != ' ')
                    fail (loc) << "incorrect first line format";

                  // Make a copy so that we don't have to deal with going past
                  // the end. We will reuse it for the name.
                  //
                  string l (v, 3, e - 3);

                  size_t pn (l.find_first_of (" !:"));

                  if (pn == 0 || l.size () == 0)
                    fail (loc) << "empty check name on first line";

                  size_t p (pn);
                  if (p != string::npos && l[p] == ' ')
                    p = l.find_first_not_of (' ', p + 1);

                  if (p != string::npos)
                  {
                    // After the switch, p is expected to be npos or the
                    // position of an unexpected character.
                    //
                    switch (l[p])
                    {
                    case '!':
                      {
                        pc.modifier = "!";

                        // See if we also have the [:<BASE>...] part.
                        //
                        p = l.find_first_not_of (' ', p + 1);
                        if (p == string::npos || l[p] != ':')
                          break;
                      }
                      // Fall through.
                    case ':':
                      {
                        // While the (space-separated) base list is kept
                        // unparsed, scan it to make sure it's valid.
                        //
                        p = l.find_first_not_of (' ', p + 1);
                        if (p == string::npos)
                          fail (loc) << "empty base list on first line";

                        size_t pb (p), eb;
                        do
                        {
                          eb = p = l.find (' ', p);
                          if (p != string::npos)
                            p = l.find_first_not_of (' ', p + 1);
                        }
                        while (p != string::npos);

                        pc.base.assign (l, pb, eb == string::npos ? eb : eb - pb);
                        break;
                      }
                    }

                    if (p != string::npos)
                      fail (loc) << "unexpected '" << l[p] << "' on first line";
                  }

                  if (pn != string::npos)
                    l.erase (pn);

                  pc.name = move (l);
                }

                // Zap continuous C++ comment/blank line blocks.
                //
                size_t b1 (b); // Beginning of non-whitespaces.
                for (; b1 != e && (v[b1] == ' ' || v[b1] == '\t'); b1++) ;

                size_t d (e - b1);

                if (d == 0) // Blank.
                {
                  // Add to the existing comment/blank block, if any.
                }
                else if (d > 1 && v[b1] == '/' && v[b1 + 1] == '/') // Comment.
                {
                  // Add to the existing comment/blank block or start new.
                  //
                  if (!p)
                    p = b;
                }
                else // Non-comment/blank line.
                {
                  // Zap the preceding comment/blank block, if any.
                  //
                  if (p)
                  {
                    size_t d (b - *p);
                    v.erase (*p, d);
                    b -= d;
                    e -= d;
                    n -= d;
                    p = nullopt;
                  }
                }
              }

              // Zap the trailing comment/blank block, if any.
              //
              if (p)
                v.erase (*p);

              // Make sure check name matches file name, including case.
              // Note that we know the file name has the .h extension.
              //
              {
                const string& s (fn.string ());
                size_t n (pc.name.size ());

                if (s.size () != n + 2 || s.compare (0, n, pc.name) != 0)
                  fail (loc) << "check name '" << pc.name
                             << "' does not match file name";
              }

              // Make sure the check body is not empty or all blank.
              //
              if (v.find_first_not_of (" \t\n\r") == string::npos)
                fail (loc) << "empty check body";

              // Make sure there are no double-quotes or backslash escaping
              // except for line continuations.
              //
              for (size_t p (0);
                   (p = v.find_first_of ("\"\\", p)) != string::npos;
                   ++p)
              {
                if (v[p] == '"')
                  fail (loc) << "double quotes";

                if (v[p] == '\\')
                {
                  if (v[++p] != '\n' && v[p] != '\r')
                    fail (loc) << "backslash escape sequence other than line "
                               << "continuation";
                }
              }

              pc.value = move (v);

              // Issue a warning if we are overriding a builtin check.
              //
              if (rule::find_builtin_check (pc.name))
              {
                warn (loc) << "check " << pc.name << " exists in builtin "
                           << "catalog, overriding" <<
                  info << "consider switching to the builtin check or" <<
                  info << "consider renaming project check (use "
                       << "autoconf.alias to retain original name in output)";
              }
#if 0
              text << f << '\n'
                   << "name: '" << pc.name << "'\n"
                   << "modf: '" << pc.modifier << "'\n"
                   << "base: '" << pc.base << "'\n"
                   << '\'' << pc.value << '\'';
#endif

              // Enter as a target if requested.
              //
              if (enter)
              {
                // The file name is absolute and normalized by construction.
                //
                dir_path d (f.directory ());
                dir_path o (rs.out_eq_src () ? dir_path () : out_src (d, rs));

                // Would have been nicer to make them h{} but we currently
                // don't have a dependency on the cc module and it's probably
                // not worth introducing just for that.
                //
                ctx.targets.insert_implied<file> (
                  move (d),
                  move (o),
                  pc.name,
                  string ("h"),
                  trace);
              }

              pcs.push_back (move (pc));

              f.make_directory (); // Strip file name.
              break;
            }
          case entry_type::unknown:
            {
              bool sl (e.ltype () == entry_type::symlink);

              fail << (sl ? "dangling symlink " : "inaccessible entry ")
                   << d / e.path () << endf;
            }
          default:
            break;
          }
        }

        // The consensus seems to be that it (may) be faster to sort at the
        // end rather than inserting elements in the sorted order.
        //
        sort (pcs.begin (), pcs.end (),
              [] (const project_check& l, const project_check& r)
              {
                return l.name < r.name;
              });

        return pcs;
      }
      catch (const system_error& e)
      {
        fail << "unable to iterate over " << d << ": " << e << endf;
      }
    }

    static const module_functions mod_functions[] =
    {
      // NOTE: don't forget to also update the documentation in init.hxx if
      //       changing anything here.

      {"autoconf", nullptr, init},
      {nullptr,    nullptr, nullptr}
    };

    const module_functions*
    build2_autoconf_load ()
    {
      return mod_functions;
    }
  }
}
