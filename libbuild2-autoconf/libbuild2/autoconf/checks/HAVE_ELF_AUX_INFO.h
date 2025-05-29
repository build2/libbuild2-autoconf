// HAVE_ELF_AUX_INFO : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ELF_AUX_INFO

/* Presence of the elf_aux_info() function, which retrieves information from
 * the auxiliary vector in ELF binaries. It is specific to FreeBSD and is used
 * to query system information at runtime, similar to getauxval() on Linux.
 * Since FreeBSD 7.0
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(7, 0)
#define HAVE_ELF_AUX_INFO 1
#endif
