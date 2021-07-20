#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void (*n_t)(void *, void *, void *);
typedef uint64_t u64;
#define Nba(n) void n(void *obr, void *abo, void *aba)
#define Alloc(bts) assert(aba + bts <= obr), aba += bts
#define Free(bts) assert(abo <= aba - bts), aba -= bts
#define Olloc(bts) obr -= bts
#define Oree(bts) obr += bts
#define A(T, v) Aba(T, 0) = v, Alloc(sizeof(void *))
// :: <T>(i) -> T
#define Aba(T, i) (((T *)aba)[i])
#define Obr(T, i) (((T *)obr)[i])
#define O(T, v) Olloc(sizeof(T)), Obr(T, 0) = v
#define T obr, abo, aba
#define C Free(sizeof(n_t)), Aba(n_t, 0)(obr, abo, aba);
#define Retreat(T, n)                                                          \
  Free(sizeof(T));                                                             \
  T n = Aba(T, 0)
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
Nba(r0) { Obr(n_t, 0)(T); }
Nba(r1) { Obr(n_t, 1)(T); }
Nba(f0) { Oree(sizeof(void *) * 3), Obr(n_t, 0)(T); }
Nba(f1) { Oree(sizeof(void *) * 3), Obr(n_t, 1)(T); }
Nba(cb) { Oree(sizeof(void *) * 3), Obr(n_t, -1)(obr, abo, aba); }
Nba(mb0) {
  Free(sizeof(void *));
  n_t narb = Aba(n_t, 0);
  Olloc(sizeof(n_t)), Obr(n_t, 0) = narb;
  Olloc(sizeof(n_t)), Obr(n_t, 0) = f1;
  Olloc(sizeof(n_t)), Obr(n_t, 0) = cb;
  Free(sizeof(void *));
  n_t nara = Aba(n_t, 0);
  nara(T);
}
Nba(mb1) {
  Retreat(n_t, narb);
  O(n_t, narb);
  O(n_t, cb);
  O(n_t, f0);
  Retreat(n_t, nara);
  nara(T);
}
// S = S ₁ a ₀ b.
Nba(S) {
  Alloc(sizeof(n_t) * 5);
  Aba(n_t, 0) = S;
  Aba(n_t, 1) = a;
  Aba(n_t, 2) = mb1;
  Aba(n_t, 3) = b;
  Aba(n_t, 4) = mb0;
  C;
}
Nba(S2) {
  A(n_t, a);
  A(n_t, S2);
  A(n_t, mb1);
  A(n_t, ε);
  A(n_t, mb0);
  C;
}
Nba(S1) {
  A(n_t, b);
  A(n_t, S2);
  A(n_t, mb1);
  C;
}
Nba(one) {
  A(int, 1);
  Obr(n_t, 1)(T);
}
Nba(add) {
  Retreat(int, r);
  Retreat(int, l);
  A(int, l + r);
  A(n_t, r1);
  C;
}
Nba(two) {
  A(n_t, one);
  A(n_t, one);
  A(n_t, mb1);
  A(n_t, add);
  A(n_t, mb1);
  C;
}
Nba(exam) {
  A(n_t, one);
  A(n_t, two);
  A(n_t, mb1);
  A(n_t, two);
  A(n_t, mb1);
  A(n_t, two);
  A(n_t, mb1);
  A(n_t, add);
  A(n_t, mb1);
  A(n_t, add);
  A(n_t, mb1);
  A(n_t, add);
  A(n_t, mb1);
  C;
}
Nba(getdata) {
  A(Q_t, 0x1122abbccddeeff0);
  A(Q_t, 0x1122abbccddeeff0);
  A(W_t, 0x9);
  Obr(n_t, 0)(T);
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
  O(n_t, logint);
  O(n_t, dump);
  A(n_t, exam);
  C;
  A(n_t, getdata);
  C;
  free(abo);
}
