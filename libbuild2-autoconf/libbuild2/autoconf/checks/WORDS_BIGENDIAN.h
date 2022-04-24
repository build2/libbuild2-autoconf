// WORDS_BIGENDIAN : BYTE_ORDER

#ifndef BYTE_ORDER
#  error BYTE_ORDER appears to be conditionally included
#endif

#undef WORDS_BIGENDIAN

#if BYTE_ORDER == BIG_ENDIAN
#  define WORDS_BIGENDIAN 1
#endif
