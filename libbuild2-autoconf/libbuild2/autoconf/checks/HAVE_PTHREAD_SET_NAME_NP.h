// HAVE_PTHREAD_SET_NAME_NP : HAVE_PTHREAD_NP_H

#undef HAVE_PTHREAD_SET_NAME_NP

/* Check for the presence of the pthread_set_name_np() function, which sets
 * the name of a thread.
 *
 * Base this check on HAVE_PTHREAD_NP_H because this function is declared in
 * pthread_np.h.
 */
#ifdef HAVE_PTHREAD_NP_H
#  define HAVE_PTHREAD_SET_NAME_NP 1
#endif
