// HAVE_TYPEOF

#undef HAVE_TYPEOF

/* Checks for support of the GNU extension typeof,
 * which allows type inference in C.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_TYPEOF 1
#endif
