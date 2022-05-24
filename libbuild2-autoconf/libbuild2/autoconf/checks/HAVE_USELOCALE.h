// HAVE_USELOCALE : HAVE_NEWLOCALE

#ifndef HAVE_NEWLOCALE
#  error HAVE_NEWLOCALE appears to be conditionally included
#endif

#undef HAVE_USELOCALE

/* @@ TODO Although this check is currently identical to HAVE_NEWLOCALE,
 *    NetBSD might add support for newlocale before uselocale (because CURRENT
 *    has a manpage for the former but not the latter).
 */
#ifdef HAVE_NEWLOCALE
#  define HAVE_USELOCALE 1
#endif
