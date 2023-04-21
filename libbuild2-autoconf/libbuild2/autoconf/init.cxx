#include <libbuild2/autoconf/init.hxx>

#include <libbuild2/scope.hxx>
#include <libbuild2/variable.hxx>
#include <libbuild2/diagnostics.hxx>

#include <libbuild2/autoconf/rule.hxx>

namespace build2
{
  namespace autoconf
  {
    static const rule rule_;

    //-
    // The `autoconf` module.
    //-
    bool
    init (scope& rs,
          scope& bs,
          const location& l,
          bool first,
          bool,
          module_init_extra&)
    {
      tracer trace ("autoconf::init");
      l5 ([&]{trace << "for " << bs;});

      if (first)
      {
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

          // Built-in checks prefix.
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

        // Register the rule.
        //
        // @@ TODO: this will be ambiguous, for example, version.in rule. Note
        //    also that if we register it for cc{}, then it will always take
        //    precedence over version.in, which is probably something we don't
        //    want. In fact, we would have liked it to be of lower precedence
        //    since version.in will only match if there is dependency on
        //    manifest.
        //
        rs.insert_rule<file> (perform_update_id,   "autoconf.in", rule_);
        rs.insert_rule<file> (perform_clean_id,    "autoconf.in", rule_);
        rs.insert_rule<file> (configure_update_id, "autoconf.in", rule_);
      }

      return true;
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
