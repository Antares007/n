#include "m.h"
N(mb0);
N(f) {
  R(int, x);
  A(int, x + 1), O(0)(T);
}
N(g) {
  R(int, x);
  A(int, x + 2), O(0)(T);
}
N(gof) { A(n_t, f), A(n_t, g), mb0(T); }
N(compose) {
  R(n_t, f);
  R(n_t, g);
  A(n_t, f), A(n_t, g), mb0(T);
}
