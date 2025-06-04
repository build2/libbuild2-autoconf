// HAVE_ARMASM

#undef HAVE_ARMASM

// Check for ARM assembly support based on compiler targeting ARM

// GCC or Clang (including Apple Clang) - Check for ARM target architecture
#if defined(__GNUC__) || defined(__clang__)
#  if defined(__ARM_ARCH) || defined(__arm__) || defined(__aarch64__)
#    define HAVE_ARMASM 1
#  endif
#endif
