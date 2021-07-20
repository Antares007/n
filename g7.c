#include "m.h"
Nba(f0) { Oree(sizeof(void *) * 3), Obr(n_t, +0)(T); }
Nba(f1) { Oree(sizeof(void *) * 3), Obr(n_t, +1)(T); }
Nba(cb) { Oree(sizeof(void *) * 3), Obr(n_t, -1)(T); }
Nba(mbo) {
  R(n_t, narb);
  O(n_t, narb), O(n_t, f1), O(n_t, cb), C;
}
Nba(mba) {
  R(n_t, narb);
  O(n_t, narb), O(n_t, cb), O(n_t, f0), C;
}
Nba(one) { A(int, 1), Obr(n_t, 1)(T); }
Nba(ro) { Obr(n_t, 0)(T); }
Nba(ra) { Obr(n_t, 1)(T); }
Nba(add) {
  R(int, r);
  R(int, l);
  A(int, l + r), A(n_t, ra), C;
}
Nba(two) { A(n_t, one), A(n_t, one), A(n_t, mba), A(n_t, add), A(n_t, mba), C; }
Nba(exam) {
  A(n_t, one), A(n_t, two), A(n_t, mba), A(n_t, two), A(n_t, mba), A(n_t, two),
      A(n_t, mba), A(n_t, add), A(n_t, mba), A(n_t, add), A(n_t, mba),
      A(n_t, add), A(n_t, mba), C;
}
Nba(getdata);
Nba(logint);
Nba(dump);
#include <stdlib.h>
Main(4096, malloc, free, O(n_t, logint), O(n_t, dump), A(n_t, exam), C,
     A(n_t, getdata), C);

//
//
//
//
//
#include "ints.h"
Nba(getdata) {
  A(Q_t, 0x1122abbccddeeff0), A(Q_t, 0x1122abbccddeeff0), A(W_t, 0x9),
      Obr(n_t, 0)(T);
}
#include <stdio.h>
Nba(logint) {
  R(int, v);
  printf("%d - %lu\n", v, aba - abo);
}
Nba(dump) {
  b_t line[33] = {[32] = '\0'};
  b_t i = 0;
  b_t b;
  while (abo < aba) {
    b = *(b_t *)abo >> 4 * 0 & 0x0f;
    line[i + 0] = b + (b < 0xa ? '0' : 'a' - 0xa);
    b = *(b_t *)abo >> 4 * 1 & 0x0f;
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
// S = S ₁ a ₀ b.
Nba(ε) {}
Nba(a) {}
Nba(b) {}
Nba(S) {
  Alloc(sizeof(n_t) * 5), Aba(n_t, -5) = S, Aba(n_t, -4) = a,
                                   Aba(n_t, -3) = mba, Aba(n_t, -2) = b,
                                   Aba(n_t, -1) = mbo, C;
}
Nba(S2) { A(n_t, a), A(n_t, S2), A(n_t, mba), A(n_t, ε), A(n_t, mbo), C; }
Nba(S1) { A(n_t, b), A(n_t, S2), A(n_t, mba), C; }
