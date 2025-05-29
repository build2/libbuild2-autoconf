// HAVE_AS_ARCHEXT_I8MM

#undef HAVE_AS_ARCHEXT_I8MM

/* Assembly feature.
 * Available in ARMV8 and later.
 * See: https://developer.arm.com/documentation/101754/0622/armclang-Reference/Other-Compiler-specific-Features/Supported-architecture-features/Matrix-Multiplication-extension?lang=en
 */
#if defined(__ARM_ARCH)
#  if __ARM_ARCH >= 8
#    define HAVE_AS_ARCHEXT_I8MM 1
#  endif
#endif
