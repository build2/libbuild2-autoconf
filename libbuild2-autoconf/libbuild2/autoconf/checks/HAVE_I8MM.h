// HAVE_I8MM

#undef HAVE_I8MM

/* Signals that the target platform supports the I8MM instructions.
 * __AMX_INT8__: This macro is defined if the compiler supports AMX-INT8 instructions.
 */
#if defined(__AMX_INT8__)
#  define HAVE_I8MM 1
#endif
