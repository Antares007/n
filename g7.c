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
#include <stdio.h>
Nba(logint) {
  R(int, v);
  printf("%d - %lu\n", v, aba - abo);
}
#include <stdlib.h>
Main(4096, malloc, free, O(n_t, logint), O(n_t, logint), A(n_t, exam), C);
