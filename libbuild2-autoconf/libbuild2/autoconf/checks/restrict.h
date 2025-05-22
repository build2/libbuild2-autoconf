// restrict!

/* Ensure restrict is available. This is a type qualifier that informs the
 * compiler that a pointer is the sole reference to a memory location,
 * allowing for optimization. If restrict is not natively supported, an
 * alternative definition may be provided.
 *
 * Note that we may not be able to redefine it because while we can undef the
 * macro, there is no guarantee we will be able to re-include the header (due
 * to include guards).
 */

/* If restrict is already defined as a macro, assume it's correct and use it
 * as-is.
 */
#ifndef restrict
/* If in C99 mode or newer, restrict is a keyword so do nothing. Otherwise, if
 * the compiler supports a variant spelling, define restrict to that.
 * Otherwise define restrict to empty.
 *
 * Note that restrict is not a C++ keyword. Plus, in MSVC, __restrict has a
 * slightly different semantics compared to C99 restrict (according to
 * Wikipedia).
 */
# if !defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L)
#   if defined(__GNUC__) || defined(__clang__)
#     define restrict __restrict__
#   elif defined(_MSC_VER)
#     define restrict __restrict
#   else
#     define restrict
#   endif
#  endif
#endif
