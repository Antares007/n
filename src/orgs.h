#pragma once
#include "evalmap.h"
#include "ints.h"
#define An_t(a) A(n_t, a)
#define AQ_t(a) A(Q_t, a)
#define Avs(a) A(void *, (void *)(a))
#define An(T, ...) EVAL(MAP(CAT(A, T), __VA_ARGS__))
