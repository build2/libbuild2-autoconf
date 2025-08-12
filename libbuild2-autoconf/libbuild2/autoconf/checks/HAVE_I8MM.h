// HAVE_I8MM

#undef HAVE_I8MM

/* Check for I8MM support.
 * I8MM is an AVX-512 extension for 8-bit integer matrix multiplication.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__AMX_INT8__)
#  define HAVE_I8MM 1
#endif