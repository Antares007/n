#include "aradani.h"
#include <stdio.h>
#include <stdlib.h>
Nar(ერთი, _(int, 1) _(n_t, O(1)));
Nar(შეკრიბე, R(int, r); R(int, l); _(int, l + r) _(n_t, O(1)));
Nar(ორი, _n(n_t, ერთი, ერთი, და, შეკრიბე, და));
Nar(შვიდი, _n(n_t, ერთი, ორი, და, ორი, და, ორი, და, შეკრიბე, და, შეკრიბე, და, შეკრიბე, და));
S(empty) {}
Nar(logint, R(int, v); printf("%d\n", v); _(n_t, empty));
Main(4096, malloc, free, _n(n_t, logint, logint, logint) PPP _(n_t, შვიდი) C);
