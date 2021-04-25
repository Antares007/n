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
#define NARG(a) arg(nt, a);
#define Cnt(nar, o, ...) C(nar, o, EVAL(MAP(NARG, __VA_ARGS__)))

////////////////////////////
// 'a', 't', 'g', 'c', 0, 0, 0, o
nargo(r0) { (((nt *)o[7])[0])(o[7], begin, advance); }
nargo(r1) { (((nt *)o[7])[1])(o[7], begin, advance); }
nargo(r2) { (((nt *)o[7])[2])(o[7], begin, advance); }
nargo(r3) { (((nt *)o[7])[3])(o[7], begin, advance); }
nargo(c47) { C(o[4], o[7]); }
nargo(c57) { C(o[5], o[7]); }
nargo(c67) { C(o[6], o[7]); }

#define MAKEmb(i)                                                              \
  nargo(mb##i) {                                                               \
    parg(nt, narb);                                                            \
    parg(nt, nara);                                                            \
    nt p[8] = {r0, r1, r2, r3, 0, 0, narb, (void *)o};                         \
    p[i] = c67;                                                                \
    C(nara, p);                                                                \
  }
MAKEmb(0) MAKEmb(1) MAKEmb(2) MAKEmb(3);
nargo(mb) { mb0(o, begin, advance); }

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
#define nar nargo
nar(button) {
  //
}
nar(counter) {
  //
  Cnt(mb, o, one, button);
}
void example(void **o, void *begin, void *advance) { //
  Cnt(mb, o, one, add2, mb, add2, mb, add2);
}

int main() {
  Ma(1 << 12, {
    nt np[8] = {hexdump, hexdump, [7] = (void *)np};
    C(example, np);
  });
}
