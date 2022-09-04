/* Test that the byte order detected at runtime matches the one detected at
 * compile time.
 */

#include <stdint.h> /* uint32_t */

#include "config.h"

/* Return:
 *
 *   0 if the runtime and compile time byte orders match
 *
 *   1 if the runtime and compile time byte orders do not match
 *
 *   2 if the BYTE_ORDER macro has a value other than BIG_ENDIAN or
 *     LITTLE_ENDIAN
 *
 *   3 if not all of the byte order macros are defined
 */
int
main ()
{
#if !defined(BYTE_ORDER) || !defined(BIG_ENDIAN) || !defined(LITTLE_ENDIAN)
  return 3;
#endif

  union {
    uint32_t i;
    unsigned char a[4];
  } u = {1};

#if BYTE_ORDER == LITTLE_ENDIAN
  return u.a[0] == 1 ? 0 : 1;
#elif BYTE_ORDER == BIG_ENDIAN
  return u.a[3] == 1 ? 0 : 1;
#else
  return 2;
#endif
}
