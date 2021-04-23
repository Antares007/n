#pragma once
#include "evalmap.h"

#define param(t, n) t n = (advance -= sizeof(t), *(t *)advance)
#define ADVANCE(v)                                                             \
  advance_ += _Generic((v), int                                                \
                       : advanceint, float                                     \
                       : advancefloat, default                                 \
                       : advancevoidptr)(advance_, v);
#define MAKEADVANCER(n, T)                                                     \
  static int n(void *advance, T v) {                                           \
    *(T *)advance = v;                                                         \
    return sizeof(T);                                                          \
  }
MAKEADVANCER(advanceint, int)
MAKEADVANCER(advancefloat, float)
MAKEADVANCER(advancevoidptr, void *)
#define apply(nar, o, ...)                                                     \
  {                                                                            \
    void *advance_ = advance;                                                  \
    EVAL(MAP(ADVANCE, __VA_ARGS__))                                            \
    nar(o, begin, advance_);                                                   \
  }

#define nargo(n, P) void n(struct P *o, void *begin, void *advance)
typedef void (*nargo_t)(void *, void *, void *);
#define pith(n, body)                                                          \
  typedef struct n {                                                           \
    body;                                                                      \
  } CAT(n, _pith);                                                             \
  typedef void (*CAT(n, _nar))(CAT(n, _pith) *, void *, void *)

#define padd(b, n, body)                                                       \
  typedef struct CAT(CAT(b, o), n) {                                           \
    CAT(b, _pith) b;                                                           \
    CAT(b, _pith) * o;                                                         \
    body;                                                                      \
  } CAT(CAT(CAT(b, o), n), _pith);                                             \
  typedef void (*CAT(CAT(CAT(b, o), n), _nar))(                                \
      CAT(CAT(CAT(b, o), n), _pith) *, void *, void *)

#define P pith
#define A padd
#define C apply
#define N nargo
#define O(ray, ...) (C(o->ray, (void *)o, __VA_ARGS__))
