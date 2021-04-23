#include "pith.h"
nargo(mbrray) { C(o[31], o[30]); }
nargo(mbr) {
  param(ntype, narb);
  param(ntype, nara);
  pith(o, op, ['r' - 'a'] = mbrray, [30] = o, [31] = narb);
  C(nara, op);
}
nargo(one) { Co('r', arg(int, 1)); }
nargo(add2) {
  param(int, a);
  Co('r', arg(int, a + 2));
}
#include "hexdump.h"
int main() {
  pith(o, p, ['l' - 'a'] = hexdump, ['r' - 'a'] = hexdump);
  Ma(1 << 12, {
    C(mbr, p,                            //
      arg(ntype, one), arg(ntype, add2), //
      arg(ntype, mbr), arg(ntype, add2), //
      arg(ntype, mbr), arg(ntype, add2)  //
    );
  })
}
