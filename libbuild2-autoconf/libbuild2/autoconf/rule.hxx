#pragma once

#include <libbuild2/types.hxx>
#include <libbuild2/utility.hxx>

#include <libbuild2/in/rule.hxx>

namespace build2
{
  namespace autoconf
  {
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
      rule ();

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
    };
  }
}
