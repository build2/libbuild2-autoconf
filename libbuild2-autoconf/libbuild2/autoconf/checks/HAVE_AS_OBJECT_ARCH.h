// HAVE_AS_OBJECT_ARCH

#undef HAVE_AS_OBJECT_ARCH

/* Check for .object_arch directive in assembly.
 * .object_arch directive specifies the target architecture in ARM object
 * files.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__ARM_ARCH)
#  define HAVE_AS_OBJECT_ARCH 1
#endif
