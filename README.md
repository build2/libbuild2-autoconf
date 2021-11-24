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
expected values based on the platform/compiler macro checks (see note at the
beginning of [Project Configuration][proj-config] for rationale).

See [`libbuild2/autoconf/checks/`][checks] for the list of available build-in
checks.

## Using in your projects

This module is part of the standard pre-installed `build2` modules and no
extra integration steps are required other than the `using` directive in
your `buildfile`. For example, for Autoconf `config.h.in`:

```
using autoconf

h{config}: in{config}
```

Or for CMake `config.h.cmake`:

```
using autoconf

h{config}: in{config.h.cmake}
```

The default falvor is `autoconf` but if the input file has the `.cmake` or
`.meson` extension, then the `cmake` or `meson` flavors are selected
automatically.  If, however, the standard `config.h.in` file is re-used for
CMake/Meson, then the flavor must be specified explicitly with the
`autoconf.flavor` variable, for example:

```
using autoconf

h{config}: in{config}
{
  autoconf.flavor = meson
}
```

Besides the built-in configuration options, custom substitutions can be
specified as `buildfile` variables in the same way as with the
[`in`][module-in] module. For example:

```
/* config.h.in */

#define PACKAGE_NAME @PACKAGE_NAME@
#define PACKAGE_VERSION @PACKAGE_VERSION@

#undef HAVE_STRLCPY
#undef HAVE_STRLCAT
```

```
h{config}: in{config}
{
  PACKAGE_NAME = $project
  PACKAGE_VERSION = $version
}
```

This mechanism can also be used to override the build-in checks, for example:

```
h{config}: in{config}
{
  HAVE_STRLCPY = true
}
```

The build-in checks can be prefixed in order to avoid clashes with similarly
named macros in other headers. This is an especially good idea if the
resulting header is public. To enable this, we specify the prefix with
the `autoconf.prefix` variable and then use the prefixed versions of
the options in the `config.h.in` file. For example:

```
/* config.h.in */

#undef LIBFOO_HAVE_STRLCPY
#undef LIBFOO_HAVE_STRLCAT
```

```
h{config}: in{config}
{
  autoconf.prefix = LIBFOO_
}
```

Note that `autoconf.prefix` only affects the lookup of the built-in checks.
Custom substitutions and overrides of build-in checks must include the
prefix. For example:

```
h{config}: in{config}
{
  autoconf.prefix = LIBFOO_

  LIBFOO_HAVE_STRLCPY = true
}
```


## Adding new checks

To add a check for a new configuration option `<NAME>` simply create the
`<NAME>.h` header file with the corresponding check and place it into
[`libbuild2/autoconf/checks/`][checks] (use existing checks for inspiration).

The first line in this header file must be in the form:

```
// <NAME>
```

Subsequent lines should be C-style comments or preprocessor directives that
`#define` or `#undef` `<NAME>` depending on whether the feature is available
(though there can be idiosyncrasies; see `const.h`, for example). Note that
there should be no double-quotes or backslashes except for line
continuations. For example:

```
// HAVE_BAR
#if !defined(_WIN32) || \
     defined(__MINGW32__)
#  define HAVE_BAR 1
#else
#  undef HAVE_BAR /* No bar on Windows except with MinGW. */
#endif
```

Note also that the module implementation may need to replace `<NAME>` with its
prefixed version if the `autoconf.prefix` functionality is in use (see above).
This is done by textually substituting every occurrence of `<NAME>` that is
separated on both left and right hand sides (that is, both characters
immediately before and after `<NAME>` are not `[A-Za-z0-9_]`).

[module-in]: https://build2.org/build2/doc/build2-build-system-manual.xhtml#module-in
[proj-config]: https://build2.org/build2/doc/build2-build-system-manual.xhtml#proj-config
[checks]: https://github.com/build2/libbuild2-autoconf/tree/master/libbuild2-autoconf/libbuild2/autoconf/checks/
