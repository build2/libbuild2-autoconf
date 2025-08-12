// HAVE_LOCAL_ALIGNED

#undef HAVE_LOCAL_ALIGNED

/* Platforms and compilers supporting alignment attributes
 */
 #if (defined(__SSE__) || defined(__AVX__) || defined(__ARM_NEON__) || defined(__ALTIVEC__)) \
     && (defined(__GNUC__) || defined(_MSC_VER))
#  define HAVE_LOCAL_ALIGNED 1
#endif
