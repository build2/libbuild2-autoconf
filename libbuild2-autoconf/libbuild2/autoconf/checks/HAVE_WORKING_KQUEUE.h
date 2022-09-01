// HAVE_WORKING_KQUEUE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_WORKING_KQUEUE

/* Since ...
 * NOTE: No reliable sources found.
         See (some) info here: https://bugs.mysql.com/bug.php?id=105562
 */

/*
   #if ...
   #  define HAVE_WORKING_KQUEUE 1
   #endif
*/
