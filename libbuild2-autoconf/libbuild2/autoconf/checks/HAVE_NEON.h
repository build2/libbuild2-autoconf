// HAVE_NEON

#undef HAVE_NEON

/* GCC, Clang: -mfpu={neon,neon-vfpv3,neon-vfpv4,neon-fp16,..}
 *
 * MSVC: Always enabled (and presumably defines at least one of
 *       __ARM_NEON[__]).
 */
#if defined(__ARM_NEON) || defined(__ARM_NEON__)
#  define HAVE_NEON 1
#endif
