// HAVE_LOONGSON3

#undef HAVE_LOONGSON3

/* MIPS-based Loongson processor.
 */
#ifdef __loongson__
    #if defined(__loongson3__)
        #define HAVE_LOONGSON3 1
    #endif
#endif
