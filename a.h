#pragma once
#pragma clang diagnostic ignored "-Wmultichar"
typedef struct p_s {
  union {
    void (*c)(struct p_s *, long, long, long);
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
typedef void (*n_t)(p_t *, long, long, long);
#define N(n) void n(p_t *ο, long α, long ρ, long σ)
#define T ο, α, ρ, σ
#define C(n, b, s, a)                                                          \
  p_t *n##ο = b;                                                               \
  crux_t *n##ξ = (crux_t *)&n##ο[(s)-4];                                       \
  long n##α = a, n##ρ, n##σ = (n##ρ = (s)-4);                                  \
  n##ξ->α = a, n##ξ->σ = n##σ
N(da);
N(daa);
N(daaa);
