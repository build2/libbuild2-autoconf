// HAVE_ALIGNED_STACK : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ALIGNED_STACK

/* Platform or compiler ensures a properly aligned stack for functions,
 * which is necessary for optimal performance
 */
// Linux: Supports x86, x86_64, ARM (32-bit and 64-bit), SPARC
#if defined(__linux__) \
  && (defined(__i386__) || defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || defined(__sparc__))
#  define HAVE_ALIGNED_STACK 1
#endif

// Windows: Supports x86, x86_64, ARM (32-bit and 64-bit)
#if defined(_WIN32) \
  && (defined(_M_IX86) || defined(_M_X64) || defined(_M_ARM) || defined(_M_ARM64))
#  define HAVE_ALIGNED_STACK 1
#endif

// macOS: Supports x86_64 and ARM64
#if defined(__APPLE__) \
  && (defined(__x86_64__) || defined(__aarch64__))
#  define HAVE_ALIGNED_STACK 1
#endif

// FreeBSD: Supports x86_64, ARM (32-bit and 64-bit), SPARC64
#if defined(__FreeBSD__) \
  && (defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || defined(__sparc64__))
#  define HAVE_ALIGNED_STACK 1
#endif

// OpenBSD: Supports x86_64, ARM (32-bit and 64-bit)
#if defined(__OpenBSD__) \
  && (defined(__x86_64__) || defined(__arm__) || defined(__aarch64__))
#  define HAVE_ALIGNED_STACK 1
#endif

// NetBSD: Supports x86_64, ARM (32-bit and 64-bit)
#if defined(__NetBSD__) \
  && (defined(__x86_64__) || defined(__arm__) || defined(__aarch64__))
#  define HAVE_ALIGNED_STACK 1
#endif

// Solaris: Supports x86_64 and SPARC64
#if defined(__sun) \
  && (defined(__x86_64__) || defined(__sparc64__))
#  define HAVE_ALIGNED_STACK 1
#endif
