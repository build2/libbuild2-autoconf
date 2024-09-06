// HAVE_ARMV8

#undef HAVE_ARMV8

/* Based on:
 * https://developer.arm.com/documentation/dui0774/g/chr1383660321827
 * https://developer.arm.com/documentation/101028/0012/5--Feature-test-macros
 */
#if defined(__ARM_ARCH)
#  if __ARM_ARCH == 8
#    define HAVE_ARMV8 1
#  endif
#endif
