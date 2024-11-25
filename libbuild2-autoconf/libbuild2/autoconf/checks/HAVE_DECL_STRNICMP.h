// HAVE_DECL_STRNICMP

#undef HAVE_DECL_STRNICMP

/* Checks if strnicmp(), a non-standard string comparison function,
 * is declared. It is commonly used in Windows environments.
 */
#if defined(_WIN32)
#  define HAVE_DECL_STRNICMP 1
#endif
