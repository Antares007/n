#include "hexdump.h"
#include "mbo.h"

static nargo(one) { Co('r', arg(int, 1)); }
static nargo(add2) {
  param(int, a);
  Co('r', arg(int, a + 2));
}
int main() {
  pith(p, trio(), ['l' - 'a'] = hexdump, ['r' - 'a'] = hexdump);
  Ma(1 << 12, C(mbr, p,                            //
                arg(ntype, one), arg(ntype, add2), //
                arg(ntype, mbr), arg(ntype, add2), //
                arg(ntype, mbr), arg(ntype, add2)  //
                ))
}
