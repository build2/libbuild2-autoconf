// HAVE_AES

#undef HAVE_AES

/* GCC, Clang: -maes
 * Checks for native AES support provided by the operating system.
 * - Windows: Supported via Cryptography API: Next Generation (CNG).
 * - macOS: Supported via CommonCrypto.
 * - BSD (OpenBSD, FreeBSD, NetBSD): Native support via system libraries.
 * - Linux: No native AES API; often relies on third-party libraries.
 * Excludes third-party libraries (e.g., OpenSSL).
 */

#if defined(__AES__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    (defined(_WIN32) && !defined(__CYGWIN__)) || \
    (defined(__APPLE__) && defined(__MACH__))
#  define HAVE_AES 1
#endif
