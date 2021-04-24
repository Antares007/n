#include <stdint.h>
#define IMP
#include "pith.h"
nargo(one) { C0(arg(int, 1)); }
nargo(add2) {
  parg(int, a);
  C0(arg(int, a + 2));
}
nargo(left) { C0(); }
nargo(printint) {
  parg(int, a);
  printf("%d\n", a);
  C0();
}
nargo(catch) {
  C0({
    _advance = begin;
    arg(int, 9);
  });
}
int main() {
  Ma(1 << 12, {
    nt np[8] = {hexdump, hexdump, [7] = (void *)np};
    C(mb0, np,                      //
      arg(nt, one), arg(nt, add2),  //
      arg(nt, mb0), arg(nt, add2),  //
      arg(nt, mb0), arg(nt, add2),  //
      arg(nt, mb0), arg(nt, catch), //
      arg(nt, mb1), arg(nt, add2),  //
      arg(nt, mb0), arg(nt, add2),  //
      arg(nt, mb0), arg(nt, add2)   //
    );
  });
}
