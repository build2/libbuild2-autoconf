// HAVE_STDC_INLINE

#undef HAVE_STDC_INLINE

/* Checks if the compiler supports standard inline functions
 * according to the C99 specification (inline).
 */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
    (defined(__clang__) || defined(__GNUC__)) || \
    (defined(_MSC_VER) && (_MSC_VER >= 1800)) /* MSVC 2013+ */
#  define HAVE_STDC_INLINE 1
#endif
