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
          bool,
          bool,
          module_init_extra&)
    {
      tracer trace ("autoconf::init");
      l5 ([&]{trace << "for " << bs;});

      // Load in.base (in.* variables, in{} target type).
      //
      load_module (rs, rs, "in.base", l);

      // Enter variables.
      //
      {
        auto& vp (rs.var_pool ());

        // Configuration file flavor. Valid values are `autoconf` (default),
        // `cmake`, and `meson`.
        //
        vp.insert<string> ("autoconf.flavor");

        // Built-in checks prefix.
        //
        vp.insert<string> ("autoconf.prefix");
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
