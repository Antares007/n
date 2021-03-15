#pragma once
#define A(T, v)                                                                \
  *(T *)(*sp) = v;                                                             \
  (*sp) += sizeof(T)
#define A2(T1, T2, v1, v2) A(T2, v2), A(T1, v1)
#define A3(T1, T2, T3, v1, v2, v3) A(T3, v3), A(T2, v2), A(T1, v1)
#define A4(T1, T2, T3, T4, v1, v2, v3, v4)                                     \
  A(T4, v4), A(T3, v3), A(T2, v2), A(T1, v1)
#define A5(T1, T2, T3, T4, T5, v1, v2, v3, v4, v5)                             \
  A(T5, v5), A(T4, v4), A(T3, v3), A(T2, v2), A(T1, v1)
#define A6(T1, T2, T3, T4, T5, T6, v1, v2, v3, v4, v5, v6)                     \
  A(T6, v6), A(T5, v5), A(T4, v4), A(T3, v3), A(T2, v2), A(T1, v1)
#define A7(T1, T2, T3, T4, T5, T6, T7, v1, v2, v3, v4, v5, v6, v7)             \
  A(T7, v7), A(T6, v6), A(T5, v5), A(T4, v4), A(T3, v3), A(T2, v2), A(T1, v1)
#define S(T, n)                                                                \
  *sp -= sizeof(T);                                                            \
  T n = *(T *)(*sp)
#define S2(T1, T2, v1, v2)                                                     \
  S(T1, v1);                                                                   \
  S(T2, v2)
#define S3(T1, T2, T3, v1, v2, v3)                                             \
  S(T1, v1);                                                                   \
  S(T2, v2);                                                                   \
  S(T3, v3)
#define S4(T1, T2, T3, T4, v1, v2, v3, v4)                                     \
  S(T1, v1);                                                                   \
  S(T2, v2);                                                                   \
  S(T3, v3);                                                                   \
  S(T4, v4);
#define S5(T1, T2, T3, T4, T5, v1, v2, v3, v4, v5)                             \
  S(T1, v1);                                                                   \
  S(T2, v2);                                                                   \
  S(T3, v3);                                                                   \
  S(T4, v4);                                                                   \
  S(T5, v5);
#define S6(T1, T2, T3, T4, T5, T6, v1, v2, v3, v4, v5, v6)                     \
  S(T1, v1);                                                                   \
  S(T2, v2);                                                                   \
  S(T3, v3);                                                                   \
  S(T4, v4);                                                                   \
  S(T5, v5);                                                                   \
  S(T6, v6);
#define S7(T1, T2, T3, T4, T5, T6, T7, v1, v2, v3, v4, v5, v6, v7)             \
  S(T1, v1);                                                                   \
  S(T2, v2);                                                                   \
  S(T3, v3);                                                                   \
  S(T4, v4);                                                                   \
  S(T5, v5);                                                                   \
  S(T6, v6);                                                                   \
  S(T7, v7);
#define N(n) void n(struct cpith *o, void **sp, void *op, void *narb)
#define N2(n1, n2) A2(nargo, nargo, n2, n1)
#define N3(n1, n2, n3) A4(nargo, nargo, nargo, nargo, mb, n1, n3, n2)
#define N4(n1, n2, n3, n4)                                                     \
  A6(nargo, nargo, nargo, nargo, nargo, nargo, mb, n1, mb, n2, n4, n3)
#define C(m) o->m(o, sp, op, narb)

struct cpith;
typedef N((*nargo));
