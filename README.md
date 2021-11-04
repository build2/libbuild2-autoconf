# libbuild2-autoconf

GNU Autoconf emulation build system module for `build2`.

Specifically, this module provides an [`in`][module-in]-based rule for
processing `config.h.in` files. Besides the Autoconf special line flavor
(`#undef`), it also supports the CMake (`#cmakedefine`) and Meson
(`#mesondefine`) variants.

Similar to Autoconf, this module provides built-in support for a number of
common `HAVE_*` configuration options. However, the values of these options
are not discovered by dynamic probing, such as trying to compile a test
program to check if the feature is present. Instead, they are set to static
expected values based on the platform/compiler macros (see note at the
beginning of [Project Configuration][proj-config] for rationale).

See [`libbuild2/autoconf/checks/`][checks] for the list of available build-in
configuration options.

## Adding new configuration options.

To add a new configuration option `<NAME>` simply create the `<NAME>.h` header
file with the corresponding check and place it into
[`libbuild2/autoconf/checks/`][checks] (use existing checks for inspiration).

The first line in this header file must be in the form:

```
// <NAME>
```

Subsequent lines should be C-style comments or preprocessor directives that
`#define` or `#undef` `<NAME>` depending on whether the feature is available
(though there can be idiosyncrasies; see `const.h`, for example).  Note that
there should be no double-quotes or backslashes except for line
continuations. For example:

```
// HAVE_FOO
#ifndef _WIN32
#  define HAVE_FOO 1
#else
#  undef HAVE_FOO /* No foo on Windows. */
#endif
```

[module-in]: https://build2.org/build2/doc/build2-build-system-manual.xhtml#module-in
[proj-config]: https://build2.org/build2/doc/build2-build-system-manual.xhtml#proj-config
[checks]: https://github.com/build2/libbuild2-autoconf/tree/master/libbuild2-autoconf/libbuild2/autoconf/checks/
