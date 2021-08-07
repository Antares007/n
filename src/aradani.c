#include "aradani.h"
static N(ddddd0) { DDDDD, A(n_t, Obr(n_t, 0)), C; }
static N(ddddd1) { DDDDD, A(n_t, Obr(n_t, 1)), C; }
static N(ddduu) { DDD, UU, C; }
N(ara) { P, AAAA(n_t, ddddd0, ddddd1, ddduu, Obr(n_t, 3)), PPPP, C; }

static N(dddu) { DDD, U, C; }
static N(dddd0) { DDDD, A(n_t, Obr(n_t, 0)), C; }
N(da) { P, AAA(n_t, dddd0, dddu, Obr(n_t, 3)), PPP, C; }

static N(dddd1) { DDDD, A(n_t, Obr(n_t, 1)), C; }
N(an) { P, AAA(n_t, dddu, dddd1, Obr(n_t, 3)), PPP, C; }

static N(dddud) { DDD, U, D, C; }
static N(ddddu) { DDD, U, D, C; }
N(anda) { PP, AAA(n_t, dddud, ddddu, Obr(n_t, 4)), C; }

static N(dddddud) { DDDDD, U, D, C; }
static N(ddddddu) { DDDDD, D, U, C; }
static N(ddduudd) { DDD, UU, DD, C; }
N(aradani) { PPP, AAAA(n_t, ddddddu, dddddud, ddduudd, Obr(n_t, 5)), C; }
