#include "m.h"
#include <stdio.h>
#include <stdlib.h>
#define Print4s(abo, aba, obr, rbs)                   \
  printf("%07lx-%02lu-%07lx-%lu-%07lx-%02lu-%07lx\n"  \
  , (unsigned long)abo&0x0FFFFFFF                     \
  , ((char*)aba - (char*)abo)/sizeof(void*)           \
  , (unsigned long)aba&0x0FFFFFFF                     \
  , (char*)obr - (char*)aba                           \
  , (unsigned long)obr&0x0FFFFFFF                     \
  , ((char*)rbs - (char*)obr)/sizeof(void*)           \
  , (unsigned long)rbs&0x0FFFFFFF)
#define PLT(l) printf(l), Print4s(abo, aba, obr, rbs),
// sss...........
// ooooosss......
// oosss.........
N(talloc) {
  R(unsigned long, size);
  void *_aba = (char *)aba + size;
  if (obr < _aba) {
    A(n_t, O(2)) C;
  } else {
    void *_abo = (char*)abo + size;
    unsigned long n = (unsigned long)((char *)aba - (char *)abo) / sizeof(void *);
    while (n--) *(void **)((char*)_abo + n * sizeof(void *)) = *(void **)((char*)abo + n * sizeof(void *));
    aba = _aba, A(void *, abo) abo = _abo, A(n_t, O(1)) C;
  }
}
N(anlog) {}
N(dalog) {
  PLT("f.")0;
  R(void*, ptr);
  ((void)ptr);
}
N(aralog){}
Main(         (10<<12),malloc,free,
              PLT("a.")
              A5(unsigned long,3,6,9,7,16)
              PLT("b.")
              A4(n_t, talloc, anlog, dalog, aralog)
              PLT("c.")
              PPP
              PLT("d.")
              C)
