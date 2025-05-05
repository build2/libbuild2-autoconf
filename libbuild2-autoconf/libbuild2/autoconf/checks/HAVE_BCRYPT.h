// HAVE_BCRYPT : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_BCRYPT

/* Presence of bcrypt functionality, specifically cryptographic operations.
 * This check in many cases refers to the Windows Cryptography API: Next Generation (CNG),
 * but other times on the *nix bcrypt library.
 *
 * - Linux (glibc 2.0), and libxcrypt is available by default on many Linux distributions.
 * - FreeBSD (5.0) includes bcrypt as a default password hashing algorithm, implemented in crypt() and libcrypt.
 * - OpenBSD (2.1) is the originator of the bcrypt password hashing algorithm and has it included by default in the system.
 * - NetBSD (3.5) includes bcrypt as part of its password hashing implementations, using libcrypt.
 * - MacOS (10.7) uses the libcrypt library.
 * - Solaris has bcrypt available through libcrypt.
 * - Windows (since Vista and Windows Server 2008) through 'Windows CNG'
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(3, 5)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 7)    || \
    BUILD2_AUTOCONF_MINGW_PREREQ(2, 0)     || \
    defined(_WIN32)                        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_BCRYPT 1
#endif
