#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void (*n_t)(void *, void *, void *);
typedef uint64_t u64;
#define Nba(n) void n(void *obr, void *abo, void *aba)
#define Advance(T, v)                                                          \
  assert(aba + sizeof(void *) <= obr), *(T *)aba = v, aba += sizeof(void *)
#define Obr(i) (((n_t *)obr)[i])
#define ObrAdd(T, v)                                                           \
  assert(aba <= obr - sizeof(T)), obr -= sizeof(T), *(T *)obr = v
#define T obr, abo, aba
#define O                                                                      \
  do {                                                                         \
    Retreat(n_t, nar);                                                         \
    nar(obr, abo, aba);                                                        \
  } while (0)
#define Retreat(T, n)                                                          \
  assert(abo <= aba - sizeof(void *));                                         \
  T n = *(T *)(aba -= sizeof(void *))
typedef int8_t b_t;
typedef int16_t w_t;
typedef int32_t d_t;
typedef int64_t q_t;
typedef uint8_t B_t;
typedef uint16_t W_t;
typedef uint32_t D_t;
typedef uint64_t Q_t;

Nba(ε) {}
Nba(a) {}
Nba(b) {}
Nba(r0) { Obr(0)(T); }
Nba(r1) { Obr(1)(T); }
Nba(f0) { Obr(3 + 0)(obr + sizeof(void *) * 3, abo, aba); }
Nba(f1) { Obr(3 + 1)(obr + sizeof(void *) * 3, abo, aba); }
Nba(cb) {
  n_t n = Obr(2);
  n(obr + sizeof(void *) * 3, abo, aba);
}
Nba(mb0) {
  Retreat(n_t, narb);
  ObrAdd(n_t, narb);
  ObrAdd(n_t, f1);
  ObrAdd(n_t, cb);
  Retreat(n_t, nara);
  nara(T);
}
Nba(mb1) {
  Retreat(n_t, narb);
  ObrAdd(n_t, narb);
  ObrAdd(n_t, cb);
  ObrAdd(n_t, f0);
  Retreat(n_t, nara);
  nara(T);
}
// S = S ₁ a ₀ b.
Nba(S) {
  Advance(n_t, S);
  Advance(n_t, a);
  Advance(n_t, mb1);
  Advance(n_t, b);
  Advance(n_t, mb0);
  O;
}
Nba(S2) {
  Advance(n_t, a);
  Advance(n_t, S2);
  Advance(n_t, mb1);
  Advance(n_t, ε);
  Advance(n_t, mb0);
  O;
}
Nba(S1) {
  Advance(n_t, b);
  Advance(n_t, S2);
  Advance(n_t, mb1);
  O;
}
Nba(one) {
  Advance(int, 1);
  Obr(1)(T);
}
Nba(add) {
  Retreat(int, r);
  Retreat(int, l);
  Advance(int, l + r);
  Advance(n_t, r1);
  O;
}
Nba(two) {
  Advance(n_t, one);
  Advance(n_t, one);
  Advance(n_t, mb1);
  Advance(n_t, add);
  Advance(n_t, mb1);
  O;
}
Nba(exam) {
  Advance(n_t, one);
  Advance(n_t, two);
  Advance(n_t, mb1);
  Advance(n_t, two);
  Advance(n_t, mb1);
  Advance(n_t, two);
  Advance(n_t, mb1);
  Advance(n_t, add);
  Advance(n_t, mb1);
  Advance(n_t, add);
  Advance(n_t, mb1);
  Advance(n_t, add);
  Advance(n_t, mb1);
  O;
}
Nba(getdata) {
  Advance(Q_t, 0x1122abbccddeeff0);
  Advance(Q_t, 0x1122abbccddeeff0);
  Advance(W_t, 0x9);
  Obr(0)(T);
}
Nba(logint) {
  Retreat(int, v);
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
#define SS (1 << 12)
int main() {
  void *obr, *abo, *aba;
  abo = aba = malloc(SS);
  obr = abo + SS;
  ObrAdd(n_t, logint);
  ObrAdd(n_t, dump);
  Advance(n_t, exam);
  O;
  Advance(n_t, getdata);
  O;
  free(abo);
}
