// HAVE_SYS_MMAN_H : HAVE_MMAP

#ifndef HAVE_MMAP
#  error HAVE_MMAP appears to be conditionally included
#endif

#undef HAVE_SYS_MMAN_H

#ifdef HAVE_MMAP
#  define HAVE_SYS_MMAN_H 1
#endif
