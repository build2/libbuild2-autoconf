#pragma once

#include <libbuild2/types.hxx>
#include <libbuild2/utility.hxx>

#include <libbuild2/in/rule.hxx>

#include <libbuild2/autoconf/checks.hxx>

namespace build2
{
  namespace autoconf
  {
    // Project-specific (as opposed to builtin) checks.
    //
    struct project_check
    {
      string name;
      string modifier; // ! or empty
      string base;     // base names (space-separated) or empty
      string value;
    };

    // Sorted in ascending order by name, similar to the builtin checks.
    //
    // We could have used a map (or hash table) but that means a separate
    // allocation per entry during construction. We don't expect a large
    // number of entires in the common case and we want to optimize load
    // performance.
    //
    using project_checks = vector<project_check>;

    // Process a config.h.{in,cmake,meson} file.
    //
    // Note that to be usable as a drop-in replacement we make the default
    // substitution symbol '@' and the mode -- lax. The user, however, is
    // still able to override both of these choices with the corresponding
    // in.* variables.
    //
    class rule: public in::rule
    {
    public:
      explicit
      rule (const project_checks&);

      virtual recipe
      apply (action, target&) const override;

      virtual void
      perform_update_depdb (action, const target&, depdb&) const override;

      virtual void
      perform_update_pre (action, const target&,
                          ofdstream&, const char*) const override;

      virtual void
      process (const location&,
               action, const target&,
               depdb&, size_t&,
               string&, size_t,
               const char*,
               char,
               bool,
               const substitution_map*,
               const optional<string>&) const override;

      virtual string
      lookup (const location&,
              action, const target&,
              const string&,
              optional<uint64_t>,
              const substitution_map*,
              const optional<string>&) const override;

      // Return the check (project or builtin) given the name or absent value
      // if not found. If unprefixable is true, then only look for an
      // unprefixable check.
      //
      optional<check>
      find_check (const char* name, bool unprefixable = false) const;

      optional<check>
      find_check (const string& name, bool unprefixable = false) const
      {
        return find_check (name.c_str (), unprefixable);
      }

      // Return the builtin check given the name or NULL if not found. If
      // unprefixable is true, then only look for an unprefixable check.
      //
      static const builtin_check*
      find_builtin_check (const char* name, bool unprefixable = false);

      static const builtin_check*
      find_builtin_check (const string& name, bool unprefixable = false)
      {
        return find_builtin_check (name.c_str (), unprefixable);
      }

    private:
      const project_checks& project_checks_;
    };
  }
}
