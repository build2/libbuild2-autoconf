#pragma once

#include <libbuild2/types.hxx>
#include <libbuild2/utility.hxx>

#include <libbuild2/module.hxx>

#include <libbuild2/autoconf/rule.hxx>

namespace build2
{
  namespace autoconf
  {
    class module: public build2::module
    {
    public:
      const project_checks checks;
      const autoconf::rule rule;

      explicit
      module (project_checks&& pcs)
          : checks (move (pcs)),
            rule (checks)
      {
      }
    };
  }
}
