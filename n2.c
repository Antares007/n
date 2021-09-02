#pragma clang diagnostic ignored "-Wmultichar"
#include <stdio.h>
#include <stdlib.h>
typedef struct p_s {
  union {
    void (*c)(struct p_s *o);
    void *v;
    char b;
    short w;
    int d;
    long q;
    unsigned char B;
    unsigned short W;
    unsigned int D;
    unsigned long Q;
  };
} p_t;
typedef void (*n_t)(p_t *);
#define S(o, a, r, s) (o[-1].Q = a, o[-2].Q = r, o[-3].Q = s, o)
#define D(o, a, r, s)                                                          \
  unsigned long a = o[-1].Q;                                                   \
  unsigned long r = o[-2].Q;                                                   \
  unsigned long s = o[-3].Q
#define α [-1].Q
#define ρ [-2].Q
#define σ [-3].Q
void add(p_t *o) {
  long l = o[--o[-1].Q].q;
  long r = o[--o[-1].Q].q;
  o[o[-1].Q++].q = l + r;
  o[o[-2].Q + 1].c(o);
}
void add1(p_t *o) {
  D(o, a, r, s);
  long lhs = o[--a].q;
  long rhs = o[--a].q;
  o[a++].q = lhs + rhs;
  o[r + 1].c(S(o, a, r, s));
}
void aaa(p_t *o) {
  unsigned long a = o[-1].Q;
  unsigned long r = o[-2].Q;
  unsigned long s = o[-3].Q;
  long lhs = o[--a].q;
  long rhs = o[--a].q;
  o[a++].q = lhs + rhs;
  o[s].c((o[-1].Q = a, o[-2].Q = r, o[-3].Q = s, o));
}
void dddd0(p_t *o) {
  D(o, a, r, s);
  r += 4;
  o[r].c(S(o, a, r, s));
}
void dddu(p_t *o) {
  D(o, a, r, s);
  r += 3;
  o[r].c(S(o, a, r + 1, s));
}
void da2(p_t *o) {
  n_t araarkhi = o[o[-2].Q + 2].c;
  o[--o[-2].Q].v = o[--o[-1].Q].v;
  o[--o[-2].Q].c = araarkhi;
  o[--o[-2].Q].c = dddu;
  o[--o[-2].Q].c = dddd0;
  o[--o[-1].Q].c(o);
}
void da(p_t *o) {
  D(o, a, r, s);
  n_t araarkhi = o[r + 2].c;
  o[--r].v = o[--a].v;
  o[--r].c = araarkhi;
  o[--r].c = dddu;
  o[--r].c = dddd0;
  o[a - 1].c(S(o, a - 1, r, s));
}
#include <stdio.h>
#include <stdlib.h>
void nar(p_t *o) { o α++; }

int main() {
  p_t *c = malloc(512 * sizeof(void *));
  p_t *o = c + 5;
  o[-1].Q = 0;
  o[-2].Q = 512;
  o[-3].Q = 512;
  o[-4].Q = 0;
  o[-5].Q = 0;
  nar(o);
  free(c);
}
