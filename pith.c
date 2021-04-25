#include <stdint.h>
#define IMP
#include "pith.h"
////////////////////////////
sargo(r0) { C(((void ***)o)[7][0], o[7]); }
sargo(r1) { C(((void ***)o)[7][1], o[7]); }
sargo(r2) { C(((void ***)o)[7][2], o[7]); }
sargo(r3) { C(((void ***)o)[7][3], o[7]); }
sargo(c47) { C(o[4], o[7]); }
sargo(c57) { C(o[5], o[7]); }
sargo(c67) { C(o[6], o[7]); }

sargo(mb0) {
  parg(nt, narb);
  parg(nt, nara);
  void *p[8] = {c67, r1, r2, r3, 0, 0, narb, (void *)o};
  C(nara, p);
}
sargo(mb1) {
  parg(nt, narb);
  parg(nt, nara);
  void *p[8] = {r0, c67, r2, r3, 0, 0, narb, (void *)o};
  C(nara, p);
}
sargo(mb) { mb0(o, begin, advance); }

sargo(one) { C(o[0], o, arg(int, 1)); }
sargo(add2) {
  parg(int, a);
  C(o[0], o, arg(int, a + 2));
}
sargo(left) { C(o[0], o); }
#define BA begin, advance
sargo(printint) {
  parg(int, a);
  printf("%d\n", a);
  ((nt)o[0])((void *)o, BA);
}
sargo(catch) {
  C(o[0], o, {
    _advance = begin;
    arg(int, 9);
  });
}
nargo(example) { //
  C(hexdump, o, {
    arg(uint64_t, -1);
    arg(uint32_t, 1);
    arg(uint16_t, -1);
    arg(uint8_t, 1);
    arg(uint8_t, 0xcc);

    arg(int64_t, -1);
    arg(int32_t, 1);
    arg(int16_t, -1);
    arg(int8_t, 1);
    arg(int8_t, 0xcc);
  });
  C(mb, o, {
    args(nt, one, add2, mb, add2, mb, add2);
    for (int i = 11; i--;) {
      args(nt, mb, add2);
    }
  });
}
int main() {
  Ma(1 << 12, {
    void *np[8] = {hexdump, hexdump, [7] = (void *)np};
    C(example, np);
  });
}
