#include "args.h"
#define IMP
#include "pith.h"

sargo(one) { C(o[0], o, args(int, 1)); }
sargo(add2) {
  parg(int, a);
  C(o[0], o, arg(int, a + 2));
}
sargo(left) { C(o[1], o, args(uint32_t, 'left')); }
sargo(catch) {
  C(o[0], o, {
    _advance = begin;
    args(uint32_t, 'ctch');
  });
}
nargo(example0) { //
  C(hexdump, o, {
    args(uint64_t, -1);
    args(uint32_t, 1);
    args(uint16_t, -1);
    args(uint8_t, 1);
    args(int8_t, 0xcc);

    args(int64_t, -1);
    args(int32_t, 1);
    args(int16_t, -1);
    args(int8_t, 1);
    args(int8_t, 0xcc);
  });
}
nargo(example1) { //
  C(mb, o, args(nt, one, add2, 0, mb, add2, 0, mb, add2, add2, catch, 0x101));
}
int main() {
  Ma(1 << 12, {
    void *oa[8] = {hexdump, hexdump, [7] = (void *)oa};
    C(example0, oa);
    C(example1, oa);
  });
}
