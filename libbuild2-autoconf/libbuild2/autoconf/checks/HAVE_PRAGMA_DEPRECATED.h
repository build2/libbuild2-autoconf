// HAVE_PRAGMA_DEPRECATED

#undef HAVE_PRAGMA_DEPRECATED

/* Support for '#pragma deprecated'
 */
#if (defined(__GNUC__) || defined(__clang__) || defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__)) \
    && !(defined(__sun__) && !defined(__GNUC__))
    // The compiler supports pragma deprecated (GCC, Clang, MSVC, MinGW)
#  define HAVE_PRAGMA_DEPRECATED 1
#endif
