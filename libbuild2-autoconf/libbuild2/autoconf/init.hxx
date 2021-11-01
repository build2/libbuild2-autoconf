#pragma once

#include <libbuild2/types.hxx>
#include <libbuild2/utility.hxx>

#include <libbuild2/module.hxx>

#include <libbuild2/autoconf/export.hxx>

namespace build2
{
  namespace autoconf
  {
    //-
    // Module `autoconf` does not require bootstrapping.
    //-
    extern "C" LIBBUILD2_AUTOCONF_SYMEXPORT const module_functions*
    build2_autoconf_load ();
  }
}
