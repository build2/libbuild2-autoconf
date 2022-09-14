// BUILD2_AUTOCONF_LIBC_VERSION!

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#define BUILD2_AUTOCONF_LIBC_VERSION

/* Include headers required to make various libc version number macros
 * available.
 *
 * Note that besides the platform-specific macros listed below, this
 * check also defines the following helper macros:
 *
 * BUILD2_AUTOCONF_GLIBC_PREREQ(maj, min)
 * BUILD2_AUTOCONF_FREEBSD_PREREQ(maj, min)
 * BUILD2_AUTOCONF_OPENBSD_PREREQ(yyyymm)
 * BUILD2_AUTOCONF_NETBSD_PREREQ(maj, min)
 * BUILD2_AUTOCONF_MACOS_PREREQ(maj, min)
 * BUILD2_AUTOCONF_MINGW_PREREQ(maj, min)
 *
 * Note that all of the above macros are always defined and evaluate to false
 * on platforms to which they do not apply. Which means that instead of:
 *
 * #if defined(__GLIBC__) && BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)
 *
 * You can just write:
 *
 * #if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)
 *
 * Note also that for checking just for the specific platform we still use one
 * of the system macros below. For example:
 *
 * #if defined(__GLIBC__)
 * #if defined(__FreeBSD__)
 * #if defined(__OpenBSD__)
 * #if defined(__NetBSD__)
 * #if defined(__MINGW32__)
 *
 * Except for MacOS specifically, which we detect using our own macro (for
 * the sake of simplicity):
 *
 * #if defined(BUILD2_AUTOCONF_MACOS)
 *
 * If, however, you want to cover the entire Apple operation systems family,
 * then use:
 *
 * #if defined(__APPLE__)
 *
 * Macros for detecting platforms and their versions:
 *
 * __GLIBC__: The glibc major version number.
 *
 * __GLIBC_MINOR__: The glibc minor version number.
 *
 * __GLIBC_PREREQ(major,minor): Return 1 if a given version number is greater
 *                              than or equal to the current glibc version
 *                              (__GLIBC__.__GLIBC_MINOR__), or 0 otherwise.
 *
 * __FreeBSD__: Defined if on FreeBSD. The value is the FreeBSD major version
 *              number but it's typically used only for OS detection. This is
 *              a predefined macro so no header needs to be included.
 *
 * __FreeBSD_version: The FreeBSD version in the following format: MMmmXXX
 *                    where `MM` is the major and `mm` the minor version
 *                    numbers. The `XXX` portion can be disregarded for the
 *                    purposes of feature checking (because it's too
 *                    fine-grained).
 *
 * __OpenBSD__: Defined if on OpenBSD. This is a predefined macro so no header
 *              needs to be included.
 *
 * OpenBSD: The OpenBSD version in the following format: YYYYMM (year and
 *          month of release). There are always two releases per year: one
 *          with an odd-numbered minor version earlier in the year and one
 *          with an even-numbered minor version later in the year. OpenBSD 7.0
 *          was released in October 2021 so its OpenBSD macro value is 202110.
 *
 *
 * __NetBSD__: Defined if on NetBSD. This is a predefined macro so no header
 *             needs to be included.
 *
 * __NetBSD_Version__: The NetBSD version in the following format: MMmmrrpp00
 *                     where `MM` is the major and `mm` the minor version
 *                     numbers, `rr` is always 0 after NetBSD version 2.0I,
 *                     and `pp` is the patch level. The `rrpp00` portion can
 *                     be disregarded for the purposes of feature checking
 *                     (because it's too fine-grained).
 *
 * __MAC_OS_X_VERSION_MIN_REQUIRED: The minimum supported Mac OS version. Up
 *                                  to Mac OS X 10.9, formatted as `MMm0`
 *                                  where `m` was the (always single-digit)
 *                                  minor version. Since Mac OS X 10.10 it is
 *                                  formatted as `MMmmpp` where `mm` is the
 *                                  (now potentially double-digit) minor
 *                                  version and `pp` is the patch version.
 *
 * __MINGW32__: Defined if on original Mingw and on Mingw-w64, both 32 and
 *              64-bit. This is a predefined macro so no header needs to be
 *              included. Note that we don't really care about original Mingw.
 *
 * __MINGW64__: Defined if on Mingw-w64, 64-bit only. This is a predefined
 *              macro so no header needs to be included.
 *
 * __MINGW64_VERSION_MAJOR:
 * __MINGW64_VERSION_MINOR: The Mingw-w64 major/minor version numbers. Note
 *                          that these are defined for both 32 and 64-bit.
 */
#if defined(__linux__)
#  include <features.h> /* __GLIBC__, __GLIBC_MINOR__, __GLIBC_PREREQ() */
#elif defined(__FreeBSD__)
#  include <osreldate.h> /* __FreeBSD_version */
#elif defined(__OpenBSD__) || defined(__NetBSD__)
/* Note: sys/param.h defines macros with common names such as ALIGN which may
 * clash with user code (see Qt).
 */
#  include <sys/param.h> /* OpenBSD, __NetBSD_Version__ */
#elif defined(__APPLE__)
#  include <Availability.h> /* __MAC_OS_X_VERSION_MIN_REQUIRED */
#elif defined(__MINGW32__)
#  include <_mingw.h> /* __MINGW64_VERSION_{MAJOR,MINOR} */
#endif

/* BUILD2_AUTOCONF_GLIBC_PREREQ(maj, min)
 *
 * Return 1 if the glibc version is >= the given version number, or 0
 * otherwise.
 *
 * __GLIBC_PREREQ() first appeared in glibc 2.2 (released in 2000) so define
 * BUILD2_AUTOCONF_GLIBC_PREREQ() using its latest glibc implementation if it
 * is not defined.
 *
 * __GLIBC__ and __GLIBC_MINOR__ first appeared in glibc 1.97 on 1996-10-22
 * (but only released in glibc 2.0 on 1997-01-26) with no preceding equivalent
 * so always return 0 if these macros are not defined.
 */
#if defined(__GLIBC__) && defined(__GLIBC_MINOR__)
#  if defined(__GLIBC_PREREQ)
#    define BUILD2_AUTOCONF_GLIBC_PREREQ(maj, min) __GLIBC_PREREQ(maj, min)
#  else
#    define BUILD2_AUTOCONF_GLIBC_PREREQ(maj, min) \
       ((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min))
#  endif
#else
#  define BUILD2_AUTOCONF_GLIBC_PREREQ(maj, min) 0
#endif

/* BUILD2_AUTOCONF_FREEBSD_PREREQ(maj, min)
 *
 * Return 1 if the FreeBSD version is >= the given version number, or 0
 * otherwise.
 */
#if defined(__FreeBSD__) && defined(__FreeBSD_version)
#  define BUILD2_AUTOCONF_FREEBSD_PREREQ(maj, min) \
     (__FreeBSD_version >= (maj)*100000 + (min)*1000)
#else
#  define BUILD2_AUTOCONF_FREEBSD_PREREQ(maj, min) 0
#endif

/* BUILD2_AUTOCONF_OPENBSD_PREREQ(yyyymm)
 *
 * Return 1 if the release date of the OpenBSD version is >= the given release
 * date, or 0 otherwise.
 */
#if defined(__OpenBSD__) && defined(OpenBSD)
#  define BUILD2_AUTOCONF_OPENBSD_PREREQ(yyyymm) (OpenBSD >= (yyyymm))
#else
#  define BUILD2_AUTOCONF_OPENBSD_PREREQ(yyyymm) 0
#endif

/* BUILD2_AUTOCONF_NETBSD_PREREQ(maj, min)
 *
 * Return 1 if the NetBSD version is >= the given version number, or 0
 * otherwise.
 */
#if defined(__NetBSD__) && defined(__NetBSD_Version__)
#  define BUILD2_AUTOCONF_NETBSD_PREREQ(maj, min) \
     (__NetBSD_Version__ >= (maj)*100000000 + (min)*1000000)
#else
#  define BUILD2_AUTOCONF_NETBSD_PREREQ(maj, min) 0
#endif

/* BUILD2_AUTOCONF_MACOS_PREREQ(maj, min)
 *
 * Return 1 if the Mac OS version is >= the given version number, or 0
 * otherwise.
 *
 * BUILD2_AUTOCONF_MACOS
 *
 * Defined if the current platform is MacOS, or undefined otherwise.
 */
#if defined(__APPLE__) && defined(__MACH__)
/* Note that just __APPLE__ covers all the Apple platforms (MacOS, iOS, etc).
 */
#  define BUILD2_AUTOCONF_MACOS 1

#  if !defined(__MAC_OS_X_VERSION_MIN_REQUIRED)
#    error __MAC_OS_X_VERSION_MIN_REQUIRED not defined
#  endif
#  if __MAC_OS_X_VERSION_MIN_REQUIRED <= 1090
#    define BUILD2_AUTOCONF_MACOS_PREREQ(maj, min) \
       (__MAC_OS_X_VERSION_MIN_REQUIRED >= (maj)*100 + (min)*10)
#  else
#    define BUILD2_AUTOCONF_MACOS_PREREQ(maj, min) \
       (__MAC_OS_X_VERSION_MIN_REQUIRED >= (maj)*10000 + (min)*100)
#  endif
#else
#  undef BUILD2_AUTOCONF_MACOS

#  define BUILD2_AUTOCONF_MACOS_PREREQ(maj, min) 0
#endif

/* BUILD2_AUTOCONF_MINGW_PREREQ(maj, min)
 *
 * Return 1 if the Mingw-w64 version is >= the given version number, or 0
 * otherwise.
 */
#if defined(__MINGW64_VERSION_MAJOR) && defined(__MINGW64_VERSION_MINOR)
#  define BUILD2_AUTOCONF_MINGW_PREREQ(maj, min)  \
            (__MINGW64_VERSION_MAJOR > (maj) ||   \
             (__MINGW64_VERSION_MAJOR == (maj) && \
              __MINGW64_VERSION_MINOR >= (min)))
#else
#  define BUILD2_AUTOCONF_MINGW_PREREQ(maj, min) 0
#endif

#endif /* BUILD2_AUTOCONF_LIBC_VERSION */
