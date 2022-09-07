/* Test more tricky SIZEOF_* checks.
 */

#include "config.h"

#include <sys/types.h> /* off_t */

#ifdef TEST_PTHREAD
#  include <pthread.h>
#endif

#undef NDEBUG
#include <assert.h>

int
main ()
{
  assert (SIZEOF_OFF_T == sizeof (off_t));

#ifdef TEST_PTHREAD
  assert (SIZEOF_PTHREAD_T == sizeof (pthread_t));
#endif

  return 0;
}
