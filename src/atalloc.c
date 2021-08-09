#include "m.h"
N(talloc) {
  R(unsigned long, size);
  void *_aba = (char *)aba + size;
  if (obr < _aba) { A(n_t, O(2)) C; return; }
  void *_abo = (char*)abo + size;
  unsigned long n = (unsigned long)((char *)aba - (char *)abo) / sizeof(void *);
  while (n--) *(void **)((char*)_abo + n * sizeof(void *)) = *(void **)((char*)abo + n * sizeof(void *));
  aba = _aba, A(void *, abo) abo =(char*)abo+ size, A(n_t, O(1)) C;
}
