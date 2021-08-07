#include "aradani.h"
S(ddddd0) { DDDDD, A(n_t, O(0)), C; }
S(ddddd1) { DDDDD, A(n_t, O(1)), C; }
S(ddduu) { DDD, UU, C; }
N(ara) { P, AAAA(n_t, ddddd0, ddddd1, ddduu, O(3)), PPPP, C; }

S(dddu) { DDD, U, C; }
S(dddd0) { DDDD, A(n_t, O(0)), C; }
N(da) { P, AAA(n_t, dddd0, dddu, O(3)), PPP, C; }
N(და) { da(T); }

S(dddd1) { DDDD, A(n_t, O(1)), C; }
N(an) { P, AAA(n_t, dddu, dddd1, O(3)), PPP, C; }

S(dddud) { DDD, U, D, C; }
S(ddddu) { DDD, U, D, C; }
N(anda) { PP, AAA(n_t, dddud, ddddu, O(4)), C; }

S(dddddud) { DDDDD, U, D, C; }
S(ddddddu) { DDDDD, D, U, C; }
S(ddduudd) { DDD, UU, DD, C; }
N(aradani) { PPP, AAAA(n_t, ddddddu, dddddud, ddduudd, O(5)), C; }
