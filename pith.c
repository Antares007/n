#include "pith.h"
static nargo(one) { Co('r', arg(int, 1)); }
static nargo(add2) {
  param(int, a);
  Co('r', arg(int, a + 2));
}
static nargo(left) { Co('l'); }
static nargo(catch) {
  Co('r', {
    _advance = begin;
    arg(int, 9);
  });
}
int main() {
  pith(p, trio(), ['l' - 'a'] = hexdump, ['r' - 'a'] = hexdump);
  Ma(1 << 12, C(mbl, p,                            //
                arg(ntype, one), arg(ntype, add2), //
                arg(ntype, mbr), arg(ntype, add2), //
                arg(ntype, mbr), arg(ntype, add2), //
                arg(ntype, mbr), arg(ntype, catch)))
}
