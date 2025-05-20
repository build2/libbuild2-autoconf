// HAVE_I686

#undef HAVE_I686

/* Defined for i686 processors (Pentium Pro and later)
 * MSVC: Check for 32-bit x86 (_M_IX86) and compatible instruction sets.
 */
#if defined(__i686__) || (defined(_MSC_VER) && defined(_M_IX86) && _M_IX86 >= 600)
#  define HAVE_I686 1
#endif
