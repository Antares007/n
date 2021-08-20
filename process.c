typedef void (*n_t)(void **ο, long α, long ρ, long σ);
long a = 10;
static long b = 0;
void z1() {}
// reset vector
void r0() __attribute__((section(".text.r0")));
void r0(void **o, long a, long r, long s) { ((n_t *)o)[r + 0](o, a, r, s); }

// stdin vector
void r1() __attribute__((section(".text.r1")));
void r1(void **o, long a, long r, long s) { ((n_t *)o)[r + 1](o, a, r, s); }

// system error vector
void r2() __attribute__((section(".text.r2")));
void r2(void **o, long a, long r, long s) { ((n_t *)o)[r + 2](o, a, r, s); }
void z0() {}
