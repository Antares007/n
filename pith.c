#include <stdint.h>
#define IMP
#include "pith.h"
////////////////////////////
#define Co(n, ...) C(o[n], o, __VA_ARGS__)
#define C0(...) Co(0, __VA_ARGS__)
#define C1(...) Co(1, __VA_ARGS__)
#define C2(...) Co(2, __VA_ARGS__)
#define C3(...) Co(3, __VA_ARGS__)
#include "evalmap.h"
#define NARG(a) arg(void *, a);
#define ntC(nar, o, ...) C(nar, o, EVAL(MAP(NARG, __VA_ARGS__)))

////////////////////////////
// 'a', 't', 'g', 'c', 0, 0, 0, o
nargo(r0) { (((nt *)o[7])[0])((void *)o[7], begin, advance); }
nargo(r1) { (((nt *)o[7])[1])((void *)o[7], begin, advance); }
nargo(r2) { (((nt *)o[7])[2])((void *)o[7], begin, advance); }
nargo(r3) { (((nt *)o[7])[3])((void *)o[7], begin, advance); }
nargo(c47) { C(o[4], o[7]); }
nargo(c57) { C(o[5], o[7]); }
nargo(c67) { C(o[6], o[7]); }
nargo(mb0) {
  parg(nt, narb);
  parg(nt, nara);
  void *p[8] = {c67, r1, r2, r3, 0, 0, narb, (void *)o};
  C(nara, p);
}
nargo(mb1) {
  parg(nt, narb);
  parg(nt, nara);
  void *p[8] = {r0, c67, r2, r3, 0, 0, narb, (void *)o};
  C(nara, p);
}
nargo(mb) { mb0(o, begin, advance); }

nargo(one) { C(o[0], o, arg(int, 1)); }
nargo(add2) {
  parg(int, a);
  C(o[0], o, arg(int, a + 2));
}
nargo(left) { C0(); }
#define BA begin, advance
nargo(printint) {
  parg(int, a);
  printf("%d\n", a);
  ((nt)o[0])((void *)o, BA);
}
nargo(catch) {
  C0({
    _advance = begin;
    arg(int, 9);
  });
}
void example(void **o, void *begin, void *advance) { //
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
    arg(uint8_t, 0xcc);
  });
  C(hexdump, o, {
    arg(uint64_t, 10);
    arg(uint64_t, 10);
  });
  ntC(mb, o, one, add2, mb, add2, mb, add2);
}
int main() {
  Ma(1 << 12, {
    void *np[8] = {hexdump, hexdump, [7] = (void *)np};
    C(example, np);
  });
}
