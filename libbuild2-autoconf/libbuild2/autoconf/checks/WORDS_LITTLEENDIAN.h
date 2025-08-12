// WORDS_LITTLEENDIAN : BYTE_ORDER

#ifndef BYTE_ORDER
#  error BYTE_ORDER appears to be conditionally included
#endif

#undef WORDS_LITTLEENDIAN

#if BYTE_ORDER == LITTLE_ENDIAN
#  define WORDS_LITTLEENDIAN 1
#endif
