// HAVE_I686

#undef HAVE_I686

/* Check for i686 processor support.
 * i686 refers to Intel Pentium Pro and later x86 processors.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC, MSVC.
 */
#if defined(__i686__) || \
    (defined(_MSC_VER) && defined(_M_IX86) && _M_IX86 >= 600)
#  define HAVE_I686 1
#endif
