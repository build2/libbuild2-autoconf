// HAVE_TYPEOF

#undef HAVE_TYPEOF

/* Checks for support of the GNU extension typeof,
 * which allows type inference in C.
 * Supported by GCC ≥ 2.5, Clang ≥ 3.0, and some other compilers.
 */

#if (defined(__GNUC__) && (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 5))) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_TYPEOF 1
#endif
