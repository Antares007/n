#include "ints.h"
#include "m.h"
#include <stdio.h>
#include <stdlib.h>
/*
Init:
      A = any array of numbers of length N
    ^ U = {(0, N-1)}
Next:
      U != {}
    ^ Pick any (b,t) in U:
        IF b != t
          THEN Pick any p in b..(t-1)
              A' = Any element of Partitions(A,p,b,t)
            ^ U' = U with (b, t) removed and
                    (b,p) and (p+1,t) added
          ELSE
              A' = A
            ^ U' = U with (b,t) removed

Partitions(B, pivot, lo, hi) =
  the set of arrays obtained from B by permuting
  B[lo], ..., B[hi] such that


*/
N(dump) {
  b_t line[33] = {[32] = '\0'};
  b_t i = 0;
  b_t b;
  while (abo < aba) {
    b = *(b_t *)abo >> 4 * 1 & 0x0f;
    line[i + 0] = b + (b < 0xa ? '0' : 'a' - 0xa);
    b = *(b_t *)abo >> 4 * 0 & 0x0f;
    line[i + 1] = b + (b < 0xa ? '0' : 'a' - 0xa);
    abo++;
    if ((i += 2) == 32) {
      i = 0;
      printf("%s\n", line);
    }
  }
  if (0 < i) {
    line[i] = '\0';
    printf("%s\n", line);
  }
}
N(asort) {
  q_t *A = &Abo(q_t, 0);
  q_t *E = &Aba(q_t, 0);
  Q_t N = E - A;
  printf("N = %lu %p %p\n", N, A, E);
}
N(getdata) { A(q_t, 8), A(q_t, 9), A(q_t, 7), asort(T); }
Main(4096, malloc, free, O(n_t, dump), O(n_t, dump), A(n_t, getdata), C);
