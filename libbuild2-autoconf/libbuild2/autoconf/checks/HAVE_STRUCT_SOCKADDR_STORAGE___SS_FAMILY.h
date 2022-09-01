// HAVE_STRUCT_SOCKADDR_STORAGE___SS_FAMILY : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SOCKADDR_STORAGE___SS_FAMILY

/* Since Linux/glibc <=2.2, OpenBSD <2.7, FreeBSD <4.0, NetBSD <1.5
 * NOTE: RFC2553 (<1999)    - defines __ss_len & __ss_family
 *       XNET draft (>1999) - defines ss_len & ss_family
 */
#if !BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)
#  define HAVE_STRUCT_SOCKADDR_STORAGE___SS_FAMILY 1
#endif
