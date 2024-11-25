// HAVE_LOONGSON2

#undef HAVE_LOONGSON2

/* MIPS-based Loongson processor.
 */
#ifdef __loongson__
    #if defined(__loongson2f__) || defined(__loongson2e__)
        #define HAVE_LOONGSON2 1
    #endif
#endif
