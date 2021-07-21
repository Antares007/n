#include "ints.h"
#include "m.h"
#include <stdio.h>
#include <stdlib.h>
Nba(getdata) {
  A(Q_t, 0x1122abbccddeeff0), A(Q_t, 0x1122abbccddeeff0), A(W_t, 0x9),
      Obr(n_t, 0)(T);
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
Main(4096, malloc, free, O(n_t, dump), O(n_t, dump), A(n_t, getdata), C);
