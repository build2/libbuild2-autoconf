# libbuild2-autoconf

GNU Autoconf emulation build system module for `build2`.

Specifically, this module provides an [`in`][module-in]-based rule for
processing `config.h.in` files. Besides the Autoconf special line flavor
(`#undef`), it also supports the CMake (`#cmakedefine`, `#cmakedefine01`) and
Meson (`#mesondefine`) variants. Note that the CMake `${VAR}` style
substitutions are not supported, only the `@VAR@` style (see
[Modifying upstream source code during build][pkg-guide-modify-upstream]
for one way to deal with `${VAR}`).

Similar to Autoconf, this module provides builtin support for a number of
common `HAVE_*` configuration checks with projects being able to add custom
ones. However, the values of these checks are not discovered by dynamic
probing, such as trying to compile a test program to determine if the feature
is present. Instead, they are set to static expected values based on the
platform/compiler macro checks (see note at the beginning of [Project
Configuration][proj-config] for rationale).

See [`libbuild2/autoconf/checks/`][checks] for the list of available builtin
checks. Submit requests for new checks as issues. Submit implementations of
new checks (or any other improvements) as PRs or patches.


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

The default flavor is `autoconf` but if the input file has the `.cmake` or
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

Besides the configuration checks, custom substitutions can be specified as
`buildfile` variables or key-value pairs in the same way as with the
[`in`][module-in] module. For example, as `buildfile` variables:

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

Or as key-value pairs in the `autoconf.substitutions` map (which is an alias
for the `in.substitutions` variable; see the [`in`][module-in] module for
details):

```
/* config.h.in */

#undef _GNU_SOURCE
#undef _POSIX_SOURCE
```

```
gnu_source = ($c.stdlib == 'glibc')
posix_source = ($c.target.class != 'windows' && !$gnu_source)

h{config}: in{config}
{
  autoconf.substitutions  = _GNU_SOURCE@$gnu_source
  autoconf.substitutions += _POSIX_SOURCE@$posix_source
}
```

In particular, the `autoconf.substitutions` mechanism is the only way to have
substitutions that cannot be specified as `buildfile` variables because they
start with an underscore (and thus are reserved, as in the above example) or
refer to one of the predefined variables.

The custom substitutions can also be used to override the checks, for example:

```
h{config}: in{config}
{
  HAVE_STRLCPY = true
}
```

While this module provides widely used aliases for some checks, it doesn't
attempt to cover every project's idiosyncrasies. Instead, it provides a
mechanism for creating project-specific aliases for builtin checks.
Specifically, the desired aliases can be specified as key-value pairs in the
`autoconf.aliases` map with the key being the new name and the value --
old/existing. For example:

```
/* config.h.in */

#undef HAVE_AF_UNIX_H
#undef MY_SSIZE_T
```

```
h{config}: in{config}
{
  autoconf.aliases  = HAVE_AF_UNIX_H@HAVE_AFUNIX_H
  autoconf.aliases += MY_SSIZE_T@ssize_t
}
```

The checks can be prefixed in order to avoid clashes with similarly named
macros in other headers. This is an especially good idea if the resulting
header is public. To enable this, we specify the prefix with the
`autoconf.prefix` variable and then use the prefixed versions of the checks in
the `config.h.in` file. For example:

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

Note that `autoconf.prefix` only affects the lookup of the checks in the
catalogs (project and builtin). Custom substitutions and overrides of checks
must include the prefix. Similarly, both names in `autoconf.aliases` must be
specified with the prefix (unless unprefixable; see below). For example:

```
h{config}: in{config}
{
  autoconf.prefix = LIBFOO_

  LIBFOO_HAVE_STRLCPY = true

  autoconf.aliases = LIBFOO_SSIZE_T@ssize_t
}
```

Note also that some check names are *unprefixable*, usually because they are
standard macro names (for example, `BYTE_ORDER`) that on some platforms come
from system headers (for example, `<sys/endian.h>` on FreeBSD). Such checks
have `!` after their names on the first line of their implementation files
(for example, `// BYTE_ORDER!`).

An implementation of a check may depend on another check. As a result,
substitutions should not be conditional at the preprocessor level (unless all
the checks are part of the same condition). Nor should the results of checks
be adjusted until after the last check. For example:

```
#ifndef _WIN32
#  cmakedefine HAVE_EXPLICIT_BZERO // Conditional substitution.
#endif

#cmakedefine HAVE_EXPLICIT_MEMSET  // Shares implementation with BZERO.

#cmakedefine BYTE_ORDER

#if BYTE_ORDER == LITTLE_ENDIAN
#  undef BYTE_ORDER               // Adjusting the result.
#endif

#cmakedefine WORDS_BIGENDIAN      // Based on BYTE_ORDER.
```

Below is the correct way to achieve the above semantics:

```
#cmakedefine HAVE_EXPLICIT_BZERO
#cmakedefine HAVE_EXPLICIT_MEMSET

#cmakedefine BYTE_ORDER
#cmakedefine WORDS_BIGENDIAN

#ifdef _WIN32
#  undef HAVE_EXPLICIT_BZERO
#endif

#if BYTE_ORDER == LITTLE_ENDIAN
#  undef BYTE_ORDER
#endif
```

## Adding new checks

There are two check catalogs: builtin, which is part of the `autoconf` module,
and project-specific. Ideally, common checks which can be used by multiple
projects should be added to the builtin rather than project catalog. In
particular, this makes sure that fixes and improvement only need to be applied
in one place rather than in all the projects that use the check.

Practically, however, there are several valid reasons why we may want to add a
project-specific check:

1. Test a common check on CI before proposing it for the builtin catalog.

2. Release a project with a common check without waiting on the `autoconf`
   release. Once the check is available as builtin, it can be dropped from
   the project catalog.

3. Override a broken builtin check with a fixed version. Similar to the
   previous case, the check can be dropped once the fix is available in
   the builtin version.

4. Have a project-private check that is unlikely to be useful to any other
   project.

Note also that adding a project check because the same builtin check has a
different name is not a valid reason: this case should be handled with
`autoconf.aliases` discussed above.

Checks from the project catalog take precedence over the builtin checks.
However, to help detect cases where a project check can be dropped (items 1-3
in the above list), the `autoconf` module issues a warning when a check with
the same name exists in both catalogs. It's recommended that private checks
(item 4) use names that can never clash with builtin checks since such checks
could be used as bases by other builtin checks (see below for details on base
checks). This can be achieved, for example, by embedding the project name in
the check name (use `autoconf.alias` to retain the original name in output).

To add a new configuration check `<NAME>` simply create the `<NAME>.h` header
file (preserving the case) which will contain the check's implementation (use
[existing checks][checks] for inspiration).

Then, if this is a project-specific check, place it into the
`build/autoconf/checks/` subdirectory of your project (or
`build2/autoconf/checks/` if using the alternative naming scheme). And if this
is a builtin check -- into [`libbuild2/autoconf/checks/`][checks] of
`libbuild2-autoconf`.

The format and semantics of this header file are exactly the same for both
project and builtin catalogs. Its first line must be in the form:

```
// <NAME>[!] [: <BASE>...]
```

If the name is followed by the `!` modifier, then it is *unprefixable* (see
the previous section for details). The name can also be followed by `:` and a
space-separated list of base checks. Such checks are automatically inserted
before the rest of the lines in the resulting substitution. One notable check
that you may want to use as a base is
[`BUILD2_AUTOCONF_LIBC_VERSION`][libc-version] (see comments for details).

Subsequent lines should be C-style comments or preprocessor directives that
`#define` or `#undef` `<NAME>` depending on whether the feature is available
(though there can be idiosyncrasies; see [`const.h`][const], for example). The
file may also contain C++-style comment lines, which (along with the first
line) are excluded from the output. Note also that there should be no
double-quotes or backslashes except for line continuations.

For example, to add a new check `HAVE_BAR`, we could create the `HAVE_BAR.h`
header file with the following content:

```
// HAVE_BAR

// TODO: maybe add support for Cygwin?

#undef HAVE_BAR

/* No bar on Windows except with MinGW. */
#if !defined(_WIN32) || \
     defined(__MINGW32__)
#  define HAVE_BAR 1
#endif
```

Note also that the module implementation may need to replace `<NAME>` with its
prefixed version (unless it is unprefixable) if the `autoconf.prefix`
functionality is in use (see above). This is done by textually substituting
every occurrence of `<NAME>` that is separated on both left and right hand
sides (that is, both characters immediately before and after `<NAME>` are not
`[A-Za-z0-9_]`).

Within a file duplicate checks are automatically suppressed. And if multiple
files are involved, then the user is expected to employ the `autoconf.prefix`
functionality to avoid clashes across files. However, this does not help
unprefixable names and, as a result, such checks should be implemented in
ways that deal with duplication (for example, include guards).

The duplicate suppression is incompatible with conditional (at the
preprocessor level) checks, for example, assuming both `HAVE_EXPLICIT_*`
checks are based on `BUILD2_AUTOCONF_LIBC_VERSION`:

```
#ifndef _WIN32
#  undef HAVE_EXPLICIT_BZERO
#endif

#undef HAVE_EXPLICIT_MEMSET
```

In this example, the `autoconf` module will omit the second copy of the
`BUILD2_AUTOCONF_LIBC_VERSION` check as part of the `HAVE_EXPLICIT_MEMSET`
substitution because it was already inserted as part of the
`HAVE_EXPLICIT_BZERO` substitution. But the first copy will not be
preprocessed on Windows.

While there is no bulletproof way to detect such situations (because the
unconditional check could be `BUILD2_AUTOCONF_LIBC_VERSION` itself; perhaps
we should only have private bases that are only accessed by the user via
derived public checks), it is a good idea for checks that are based on
other checks to verify that the base macros are in fact defined, for example:

```
// HAVE_EXPLICIT_BZERO : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

...
```

[module-in]: https://build2.org/build2/doc/build2-build-system-manual.xhtml#module-in
[proj-config]: https://build2.org/build2/doc/build2-build-system-manual.xhtml#proj-config
[checks]: https://github.com/build2/libbuild2-autoconf/tree/master/libbuild2-autoconf/libbuild2/autoconf/checks/
[libc-version]: https://github.com/build2/libbuild2-autoconf/tree/master/libbuild2-autoconf/libbuild2/autoconf/checks/BUILD2_AUTOCONF_LIBC_VERSION.h
[const]: https://github.com/build2/libbuild2-autoconf/tree/master/libbuild2-autoconf/libbuild2/autoconf/checks/const.h
[pkg-guide-modify-upstream]: https://build2.org/build2-toolchain/doc/build2-toolchain-packaging.xhtml#howto-patch-upstream-source-build
