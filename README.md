# libbuild2-autoconf

GNU Autoconf emulation build system module for `build2`.

Specifically, this module provides an [`in`][module-in]-based rule for
processing `config.h.in` files. Besides the Autoconf flavor, it also supports
CMake and Meson variants.

Similar to Autoconf, the module provides built-in support for a number of
common `HAVE_*` configuration options. However, the values of these options
are not discovered by probing, such as trying to compile a test program to
check if the header is present. Instead, they are set to the expected values
based on the platform/compiler macros.

[module-in]: https://build2.org/build2/doc/build2-build-system-manual.xhtml#module-in
