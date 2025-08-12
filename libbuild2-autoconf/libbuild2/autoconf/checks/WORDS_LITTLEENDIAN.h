// WORDS_LITTLEENDIAN : BYTE_ORDER

#ifndef BYTE_ORDER
#  error BYTE_ORDER appears to be conditionally included
#endif

#undef WORDS_LITTLEENDIAN

/* Check if current byte-order is little-endian.
 *
 * Available on Linux, *BSD, MacOS, Windows including MinGW and Cygwin.
 */
#if BYTE_ORDER == LITTLE_ENDIAN
#  define WORDS_LITTLEENDIAN 1
#endif
