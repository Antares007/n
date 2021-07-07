#define N(n, T) void n(struct T *o, void *b, void *a)
#define A(T, v) *(T *)a = v, a += sizeof(void *)
#define P(T, n) T n = *(T *)(a -= sizeof(void *))
struct ba_pith_s;
typedef void (*ba_nar_t)(struct ba_pith_s *, void *, void *);
struct ba_pith_s {
  ba_nar_t b;
  ba_nar_t a;
};
N(mb, ba_pith_s);
N(ma, ba_pith_s);
