#include <libbuild2/autoconf/rule.hxx>

#include <cstring> // strcmp()

#include <libbuild2/depdb.hxx>
#include <libbuild2/target.hxx>
#include <libbuild2/algorithm.hxx>
#include <libbuild2/diagnostics.hxx>

#include <libbuild2/in/target.hxx>

#include <libbuild2/autoconf/checks.hxx>

using namespace std;

namespace build2
{
  namespace autoconf
  {
    enum class flavor {autoconf, cmake, meson};

    struct match_data
    {
      autoconf::flavor flavor;
      string           prefix;
    };

    rule::
    rule ()
        : in::rule ("autoconf.in 1",
                    "autoconf.in",
                    '@'   /* symbol */,
                    false /* strict */)
    {
      static_assert (sizeof (match_data) <= target::data_size,
                     "insufficient space");
    }

    recipe rule::
    apply (action a, target& t) const
    {
      recipe r (in::rule::apply (a, t));

      // Determine and cache the configuration file flavor.
      //
      flavor f (flavor::autoconf);

      if (const string* s = cast_null<string> (t["autoconf.flavor"]))
      {
        if      (*s == "cmake") f = flavor::cmake;
        else if (*s == "meson") f = flavor::meson;
        else if (*s != "autoconf")
          fail << "invalid configuration file flavor '" << *s << "'";
      }
      else
      {
        // If the in{} file extension is either .cmake or .meson, then
        // use that as the flavor.
        //
        for (const target* pt: t.prerequisite_targets[a])
        {
          if (pt != nullptr)
          {
            if (const auto* it = pt->is_a<in::in> ())
            {
              string e (it->path ().extension ());

              if      (e == "cmake") f = flavor::cmake;
              else if (e == "meson") f = flavor::meson;

              break;
            }
          }
        }
      }

      // Get the prefix if any.
      //
      string p (cast_empty<string> (t["autoconf.prefix"]));

      t.data (match_data {f, move (p)});

      return r;
    }

    void rule::
    perform_update_depdb (action, const target& t, depdb& dd) const
    {
      tracer trace ("autoconf::rule::perform_update_depdb");

      const match_data& md (t.data<match_data> ());

      // Then the flavor.
      //
      if (dd.expect (md.flavor == flavor::autoconf ? "autoconf" :
                     md.flavor == flavor::cmake    ? "cmake" :
                     "meson") != nullptr)
        l4 ([&]{trace << "flavor mismatch forcing update of" << t;});

      // Then the prefix.
      //
      if (dd.expect (md.prefix) != nullptr)
        l4 ([&]{trace << "prefix mismatch forcing update of" << t;});

      // Note that at first it may seem necessary to add something like the
      // full module version in lieu of the built-in checks database hash.
      // Note, however, that any changes will be automatically taken care of
      // (and with better precision) as part of the substituted variable value
      // checks by in::rule.
    }

    void rule::
    process (const location& l,
             action a, const target& t,
             depdb& dd, size_t& dd_skip,
             string& s, size_t b,
             const char* nl,
             char sym,
             bool strict,
             const optional<string>& null) const
    {
      auto ws = [] (char c)
      {
        return c == ' ' || c == '\t';
      };

      auto skip_ws = [&ws] (const string& s, size_t& b)
      {
        for (; ws (s[b]); ++b) ;
      };

      // Scan a C identifier returning its size. Return 0 if it's not a valid
      // identifier or is followed by a non-whitespace.
      //
      auto read_id = [&ws] (const string& s, size_t b) -> size_t
      {
        size_t i (b);
        char c;
        for (; (c = s[i]) == '_' || (i == b ? alpha (c) : alnum (c)); ++i) ;

        return i != b && (c == '\0' || ws (c)) ? i - b : 0;
      };

      size_t i (b);

      flavor f (t.data<match_data> ().flavor);

      // Substitute special #undef/#cmakedfine/#mesondefine line. If value is
      // false, then do not append the value to #define.
      //
      // Return true if it was substituted with #define, false if with #undef,
      // and nullopt if with a custom block of preprocessor directives.
      //
      auto substitute_special = [&skip_ws, this,
                                 &l,
                                 a, &t,
                                 &dd, &dd_skip,
                                 nl, strict, &null,
                                 &s] (const string& name,
                                      bool value = true) -> optional<bool>
      {
        // Note that we must be careful here with going too ad hoc since there
        // is a parallel debdb change tracking logic in in::rule which calls
        // substitute(). So we use the lookup flags to mark special
        // substitutions.
        //
        optional<string> ov (substitute (l,
                                         a, t,
                                         dd, dd_skip,
                                         name, 1 /* flags */,
                                         strict, null));

        assert (ov); // C identifier is a valid variable name.
        string& v (*ov);

        // As an extension, we allow replacing the entire line with a
        // potentially multi-line block of preprocessor directives. To detect
        // this, we look for a line that starts with `#` after whitespaces.
        //
        size_t p (0);
        for (;; ++p)
        {
          skip_ws (v, p);

          if (v[p] == '#')
            break;

          p = v.find ('\n', p);

          if (p == string::npos)
            break;
        }

        optional<bool> r;
        if (p != string::npos)
        {
          s.clear ();

          // Skip leading and trailing newlines.
          //
          for (; v.back () == '\n' || v.back () == '\r'; v.pop_back ()) ;
          for (p = 0; v[p] == '\n' || v[p] == '\r'; ++p) ;

          for (;; ++p)
          {
            size_t b (p);
            p = v.find ('\n', p);

            size_t n (p == string::npos
                      ? p
                      : p - b - (v[p - 1] == '\r' ? 1 : 0));

            s.append (v, b, n);

            if (p == string::npos)
              break;

            s.append (nl); // Last line is added by our caller.
          }
        }
        // Otherwise translate false/0 to #undef and true to 1.
        //
        else if (v == "false" || v == "0")
        {
          s = "#undef ";
          s += name;
          r = false;
        }
        else
        {
          s = "#define ";
          s += name;
          if (value)
          {
            if (v == "true")
              v = "1";
            else if (v != "1")
              replace_newlines (v, nl);

            s += ' ';
            s += v;
          }
          r = true;
        }

        return r;
      };

      // Deal with special lines of each flavor. Return if the line has has
      // been handled and fall through to use the normal substitution logic.
      //
      switch (f)
      {
      case flavor::autoconf:
        {
          // Autoconf recognizes two forms of special lines:
          //
          // #undef NAME
          // #define NAME 0
          //
          // However, the latter form as well as comments after NAME in the
          // former form are "strongly discouraged". So for now we only
          // recognize #undef, especially seeing that it's the dominant form
          // in the wild.
          //
          skip_ws (s, i);

          if (s[i] == '#')
          {
            ++i;
            skip_ws (s, i);

            if (s.compare (i, 5, "undef") == 0 && ws (s[i + 5]))
            {
              i += 5;
              skip_ws (s, i);

              size_t n (read_id (s, i));

              if (n == 0)
                fail (l) << "expected identifier after #undef";

              string name (s, i, n);

              i += n;
              skip_ws (s, i);

              // Let's not bother with detecting comments seeing that it's
              // strongly discouraged.
              //
              if (s[i] != '\0')
                fail (l) << "junk after identifier " << name;

              substitute_special (name);
              return;
            }
            else if (s.compare (i, 11, "cmakedefine") == 0)
            {
              warn (l) << "#cmakedefine in autoconf configuration file" <<
                info << "did you forget to specify autoconf.flavor=cmake?";
            }
            else if (s.compare (i, 11, "mesondefine") == 0)
            {
              warn (l) << "#mesondefine in autoconf configuration file" <<
                info << "did you forget to specify autoconf.flavor=meson?";
            }
          }
          break;
        }
      case flavor::cmake:
        {
          // CMake recognizes two forms of special lines:
          //
          // #cmakedefine NAME [VALUE]
          // #cmakedefine01 NAME
          //
          // The first variant is replaced with #define if NAME is "set to any
          // value not considered false" and to (commented out) #undef
          // otherwise. In the former case, if VALUE is present, then it is
          // processed normally with @-substitutions. So in a sense there are
          // two entities at play: variable NAME controls #define/#undef while
          // VALUE -- the value in case of #define. The following patterns are
          // fairly common:
          //
          // #cmakedefine HAVE_MEMORY_H
          // #cmakedefine HAVE_MEMORY_H 1
          // #cmakedefine SIZEOF_LONG @SIZEOF_LONG@
          //
          // But also:
          //
          // #cmakedefine const
          // #cmakedefine const @HAVE_CONST@
          // #cmakedefine size_t @SIZE_T@
          //
          // The #cmakedefine01 variant is always replaced with #define,
          // either with value 1 if NAME is true and 0 otherwise. It's doesn't
          // appear to be used much in practice so we are not going to bother
          // with it.
          //
          skip_ws (s, i);

          if (s[i] == '#')
          {
            ++i;
            skip_ws (s, i);

            if (s.compare (i, 11, "cmakedefine") == 0 && ws (s[i + 11]))
            {
              i += 11;
              skip_ws (s, i);

              size_t n (read_id (s, i));

              if (n == 0)
                fail (l) << "expected identifier after #cmakedefine";

              string name (s, i, n);

              i += n;
              skip_ws (s, i);

              // If there is value, then save it for later (see below).
              //
              optional<string> value;
              if (s[i] != '\0')
                value = string (s, i);

              optional<bool> r (substitute_special (name, !value));

              if (!value || !r || !*r)
                return;

              // Append the value and fall through to the normal substitution
              // logic.
              //
              s += ' ';
              b = s.size (); // Start substituting from here.
              s += *value;
            }
            else if (s.compare (i, 13, "cmakedefine01") == 0 && ws (s[i + 13]))
              fail(l) << "#cmakedefine01 is not yet supported";
          }
          break;
        }
      case flavor::meson:
        {
          // Meson recognizes only one special form:
          //
          // #mesondefine NAME
          //
          // It is replaced with commented out #undef if NAME is not set, with
          // #undef if NAME is set to boolean false, with #define without a
          // value if it is set to boolean true, and to #define with the value
          // of NAME if it is set to integer or string.
          //
          // Since we don't do commented out #undef, we will treat the first
          // two cases the same. We will also map the third case to value 1,
          // similar to Autoconf.
          //
          skip_ws (s, i);

          if (s[i] == '#')
          {
            ++i;
            skip_ws (s, i);

            if (s.compare (i, 11, "mesondefine") == 0 && ws (s[i + 11]))
            {
              i += 11;
              skip_ws (s, i);

              size_t n (read_id (s, i));

              if (n == 0)
                fail (l) << "expected identifier after #mesondefine";

              string name (s, i, n);

              i += n;
              skip_ws (s, i);

              if (s[i] != '\0')
                fail (l) << "junk after identifier " << name;

              substitute_special (name);
              return;
            }
          }
          break;
        }
      }

      in::rule::process (l, a, t, dd, dd_skip, s, b, nl, sym, strict, null);
    }

    string rule::
    lookup (const location& l,
            action a, const target& t,
            const string& n,
            optional<uint64_t> flags,
            const optional<string>& null) const
    {
      if (flags)
      {
        assert (*flags == 1);

        // If this is a special substitution, then look in our catalog of
        // built-in checks. Specifically, the plan is as follows:
        //
        // 1. Look in the catalog and fall through if not found.
        //
        // 2. If found, then check for a custom value falling through if
        //    found.
        //
        //    Here things get a bit tricky: while a stray HAVE_* buildfile
        //    variable is unlikely, something like const or volatile is
        //    possible. Since there is no way to undefine a buildfile variable
        //    (becasue we could always see a value from the outer scope), we
        //    will treat null as an indication to use the built-in check.
        //    While this clashes with the in.null semantics, it's just as
        //    easy to set the variable to the real default value as to null.
        //
        // 3. Return the build-in value form the catalog.
        //
        const char* pn (nullptr); // Prefix-less name.

        const string& p (t.data<match_data> ().prefix);
        if (!p.empty ())
        {
          // Note that if there is no prefix, then we don't look for a
          // built-in check.
          //
          if (n.size () > p.size () && n.compare (0, p.size (), p) == 0)
            pn = n.c_str () + p.size ();
        }
        else
          pn = n.c_str ();

        if (pn != nullptr)
        {
          const check* e (checks + sizeof (checks) / sizeof (*checks));
          const check* i (lower_bound (checks, e,
                                       pn,
                                       [] (const check& c, const char* pn)
                                       {
                                         return strcmp (c.name, pn) < 0;
                                       }));

          // Note: original name in lookup.
          //
          if (i != e && strcmp (i->name, pn) == 0 && !t[n])
          {
            string r (i->value);

            // Add "back" the prefix.
            //
            if (!p.empty ())
            {
              auto sep = [] (char c) { return !alnum (c) && c != '_'; };

              size_t m (n.size () - p.size ()); // Prefix-less name length.

              for (size_t i (0); (i = r.find (pn, i)) != string::npos; i += m)
              {
                if ((i     == 0         || sep (r[i - 1])) &&
                    (i + m == r.size () || sep (r[i + m])))
                {
                  r.insert (i, p);
                  i += p.size ();
                }
              }
            }

            return r;
          }
        }
      }

      return in::rule::lookup (l, a, t, n, nullopt, null);
    }
  }
}
