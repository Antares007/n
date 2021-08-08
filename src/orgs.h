#pragma once
#include "evalmap.h"
#include "ints.h"

#define COMMA ,
#define ARG_n_t(a) A(n_t, a) COMMA
#define ARG_Q_t(a) A(Q_t, a) COMMA
#define ARG_vs(a) A(void*, (void*)(a)) COMMA
#define args(T, ...) EVAL(MAP(CAT(ARG_, T), __VA_ARGS__))
#define _(T, a) A(T, a) COMMA
#define _n(T, ...) args(T, __VA_ARGS__)
#define Nar(n, ...)                                                            \
  N(n) { __VA_ARGS__ C; }
#define Sar(n, ...)                                                            \
  S(n) { __VA_ARGS__ C; }
