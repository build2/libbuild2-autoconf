/* Verify existence of instruction set
 * https://github.com/gcc-mirror/gcc/blob/9bbad3685131ec95d970f81bf75f9556d4d92742/gcc/config/rs6000/altivec.h#L33-L35
 */

#include "config.h"

#ifdef HAVE_ALTIVEC
#  include <altivec.h>
#endif

int
main ()
{
#ifdef HAVE_ALTIVEC
  vector signed int v1 = (vector signed int) { 0 };
  vector signed int v2 = (vector signed int) { 1 };
  v1 = vec_add(v1, v2);
#endif

  return 0;
}
