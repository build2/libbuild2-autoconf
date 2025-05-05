// restrict!

/* If restrict is already defined, assume it's correct and use it as-is.
 *
 * Note that we may not be able to redefine it because while we can undef the
 * macro, there is no guarantee we will be able to re-include the header (due
 * to include guards).
 *
 * Determines whether the C99 restrict keyword is supported by the compiler.
 * The restrict keyword is a type qualifier that informs the compiler that
 * a pointer is the sole reference to a memory location, allowing for
 * optimization. If restrict is not natively supported, an alternative
 * definition may be provided.
 */
#ifndef restrict
  /* POSIX and MinGW (which also has <sys/types.h> that defines restrict).
   */
/* Check for C99 or compiler-specific support for `restrict`. */
# if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#   define restrict restrict
# elif defined(__GNUC__) || defined(__clang__)
#   define restrict __restrict__
# elif defined(_MSC_VER)
#   define restrict __restrict
# endif
#endif
