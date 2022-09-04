// SIZEOF_PTHREAD_T

#undef SIZEOF_PTHREAD_T

#ifndef _WIN32
#   if defined(__APPLE__)
#       ifdef __LP64__
#           define SIZEOF_PTHREAD_T 8
#       else
#           define SIZEOF_PTHREAD_T 4
#       endif
#   else
#       define SIZEOF_PTHREAD_T 4
#   endif
#endif
