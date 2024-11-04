// HAVE_GNU_AS

#undef HAVE_GNU_AS

/* GNU Assembler (as) is commonly available in environments like
 * Linux, MinGW, and Cygwin, where the GNU toolchain is standard.
 */
#if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__)
    #define HAVE_GNU_AS 1
#endif
