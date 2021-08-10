#include "m.h"
#include <stdio.h>
#include <stdlib.h>
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
    while (n) n--, *(void **)((char*)_abo + n * sizeof(void *)) = *(void **)((char*)abo + n * sizeof(void *));
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
              P P P
              PLT("d.")
              C)
