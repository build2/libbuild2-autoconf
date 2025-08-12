// HAVE_LDEXPF

#undef HAVE_LDEXPF

/* Check for the ldexpf() function.
 * ldexpf() multiplies a floating-point number by an integral power of 2.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC, Clang, MSVC 1800 or later.
 */
#if (__STDC_VERSION__ >= 199901L)             || \
    defined(__GNUC__)                         || \
    defined(__clang__)                        || \
    (defined(_MSC_VER) && (_MSC_VER >= 1800)) || \
    defined(_POSIX_VERSION)
#  define HAVE_LDEXPF 1
#endif
