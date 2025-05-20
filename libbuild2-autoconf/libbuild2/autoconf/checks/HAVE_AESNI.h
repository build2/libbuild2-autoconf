// HAVE_AESNI

#undef HAVE_AESNI

/* Checks for the availability of AES-NI (Advanced Encryption Standard New Instructions),
 * which accelerates AES encryption and decryption.
 * Requirements:
 * - Supported CPU architecture: x86 or x86_64 with AES-NI instructions.
 * - Supported compilers: GCC, Clang, Intel, or MSVC with AES-NI enabled.
 * - Target OS: Any, as long as the CPU and compiler support AES-NI.
 */

#if (defined(__x86_64__) || defined(_M_X64) || defined(__i386__) || defined(_M_IX86)) && \
    (defined(__AES__) || (defined(_MSC_VER) && defined(__AVX__)))
#  define HAVE_AESNI 1
#else
#  define HAVE_AESNI 0
#endif
