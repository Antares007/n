#include "aradani.h"
S(ddddd0) { DDDDD, A(n_t, Obr(n_t, 0)), C; }
S(ddddd1) { DDDDD, A(n_t, Obr(n_t, 1)), C; }
S(ddduu) { DDD, UU, C; }
N(ara) { P, AAAA(n_t, ddddd0, ddddd1, ddduu, Obr(n_t, 3)), PPPP, C; }

S(dddu) { DDD, U, C; }
S(dddd0) { DDDD, A(n_t, Obr(n_t, 0)), C; }
N(da) { P, AAA(n_t, dddd0, dddu, Obr(n_t, 3)), PPP, C; }

S(dddd1) { DDDD, A(n_t, Obr(n_t, 1)), C; }
N(an) { P, AAA(n_t, dddu, dddd1, Obr(n_t, 3)), PPP, C; }

S(dddud) { DDD, U, D, C; }
S(ddddu) { DDD, U, D, C; }
N(anda) { PP, AAA(n_t, dddud, ddddu, Obr(n_t, 4)), C; }

S(dddddud) { DDDDD, U, D, C; }
S(ddddddu) { DDDDD, D, U, C; }
S(ddduudd) { DDD, UU, DD, C; }
N(aradani) { PPP, AAAA(n_t, ddddddu, dddddud, ddduudd, Obr(n_t, 5)), C; }
