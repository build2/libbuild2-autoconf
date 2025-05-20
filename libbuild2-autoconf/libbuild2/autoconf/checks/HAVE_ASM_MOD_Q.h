// HAVE_ASM_MOD_Q

#undef HAVE_ASM_MOD_Q

/* Check if the 'modq' assembly instruction is available, which may be used
 * in x86-64 environments with specific assemblers.
 * This instruction is non-standard and might not be universally supported.
 */
#if defined(__x86_64__) || defined(_M_X64)
    #if defined(__GNUC__) || defined(__clang__)
        // GCC and Clang can support inline assembly with 'modq'
        #define HAVE_ASM_MOD_Q 1
    #elif defined(_MSC_VER)
        // MSVC does not natively support 'modq' but might support equivalent
        // operations depending on the intrinsic and inline assembly
        // options (older MSVC might lack support)
        #define HAVE_ASM_MOD_Q 1
    #endif
#endif
