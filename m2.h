#pragma once
#pragma clang diagnostic ignored "-Wmultichar"
typedef struct p_s {
  union {
    void (*c)(struct p_s *, long, long, long);
    void *v;
    char  b;
    short w;
    int   d;
    long  q;
    unsigned char  B;
    unsigned short W;
    unsigned int   D;
    unsigned long  Q;
  };
} p_t;
typedef void (*n_t)(p_t *, long, long, long);
#define N(n) void n(p_t *ο, long α, long ρ, long σ)
#define R(T, n) T n = (T)ο[--α].v
#define A(a) ο[α++].v = (void *)a,
#define A2(a, ...) A(a) A(__VA_ARGS__)
#define A3(a, ...) A(a) A2(__VA_ARGS__)
#define A4(a, ...) A(a) A3(__VA_ARGS__)
#define A5(a, ...) A(a) A4(__VA_ARGS__)
#define A6(a, ...) A(a) A5(__VA_ARGS__)
#define A7(a, ...) A(a) A6(__VA_ARGS__)
#define A8(a, ...) A(a) A7(__VA_ARGS__)
#define A9(a, ...) A(a) A8(__VA_ARGS__)
#define A10(a, ...) A(a) A9(__VA_ARGS__)
#define A11(a, ...) A(a) A10(__VA_ARGS__)
#define A12(a, ...) A(a) A11(__VA_ARGS__)
#define A13(a, ...) A(a) A12(__VA_ARGS__)
#define A14(a, ...) A(a) A13(__VA_ARGS__)
#define A15(a, ...) A(a) A14(__VA_ARGS__)
#define A16(a, ...) A(a) A15(__VA_ARGS__)
#define A17(a, ...) A(a) A16(__VA_ARGS__)
#define A18(a, ...) A(a) A17(__VA_ARGS__)
#define A19(a, ...) A(a) A18(__VA_ARGS__)
#define A20(a, ...) A(a) A19(__VA_ARGS__)
#define A21(a, ...) A(a) A20(__VA_ARGS__)
#define On_t(i) ((n_t *)ο)[i].c
#define O(a) ο[--ρ].c = a,
#define O2(a, ...) O(__VA_ARGS__) O(a)
#define O3(a, ...) O2(__VA_ARGS__) O(a)
#define O4(a, ...) O3(__VA_ARGS__) O(a)
#define T ο, α, ρ, σ
#define Or0 ο[ρ + 0].c
#define Or1 ο[ρ + 1].c
#define Or2 ο[ρ + 2].c
#define Os1 ο[σ - 1].c
#define U ο[α++].v = ο[ρ++].v,
#define U2 U U
#define U3 U2 U
#define U4 U3 U
#define P ο[--ρ].v = ο[--α].v,
#define P2 P P
#define P3 P2 P
#define P4 P3 P
#define D ρ += 1,
#define D2 D D
#define D3 D2 D
#define D4 D3 D
#define D5 D4 D
#define D6 D5 D
