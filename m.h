typedef void (*n_t)(void **ο, long α, long ρ, long σ);
#define N(n) void(n)(void **ο, long α, long ρ, long σ)
#define S(n) static N(n)
#define Dot(n) ((n_t*)CAT(n,ο))[CAT(n,α)-1](CAT(n,ο),CAT(n,α)-1,CAT(n,ρ),CAT(n,σ));
#define O(n, ...)                                                              \
  do {                                                                         \
    void **_ο = n##ο;                                                          \
    long _α = n##α, _ρ = n##ρ, _σ = n##σ;                                      \
    void **ο = _ο;                                                             \
    long α = _α, ρ = _ρ, σ = _σ;                                               \
    __VA_ARGS__((n_t *)ο)[α - 1](ο, α - 1, ρ, σ);                              \
  } while (0)
#define CT(n, s, r, a, o)                                                      \
  unsigned long n##σ = s, n##ρ = r, n##α = a;                                  \
  void **n##ο = o
#define Nt(n, b, s) CT(n, (unsigned long)s, (unsigned long)s, 0, b)
#define At(n,nt) A(n,CAT(nt,ο))A(n,CAT(nt,α))A(n,CAT(nt,ρ))A(n,CAT(nt,σ))
#define R(T, n) T n = (T)ο[--α]
#define CAT_(a,b) a##b
#define CAT(a,b) CAT_(a,b)
#define RT(n) R(unsigned long, CAT(n,σ));R(unsigned long, CAT(n,ρ));R(unsigned long, CAT(n,α));R(void**, CAT(n,ο))
#define P(n,a) CAT(n,ο)[--CAT(n,ρ)] = (void *)a,
#define P3(n,a,b,c) P(n,c)P(n,b)P(n,a)
#define A(n, a) CAT(n,ο)[CAT(n,α)++] = (void *)a,
#define A2(n,a, b) A(n,a) A(n,b)
#define A3(n,a, b, c) A(n,a) A(n,b) A(n,c)
#define A4(n,a, b, c, d) A(n,a) A(n,b) A(n,c) A(n,d)
#define A5(n,a, b, c, d, e) A(n,a) A(n,b) A(n,c) A(n,d) A(n,e)
#define A6(n,a, b, c, d, e, f) A(n,a) A(n,b) A(n,c) A(n,d) A(n,e) A(n,f)
#define A7(n,a, b, c, d, e, f, g) A(n,a) A(n,b) A(n,c) A(n,d) A(n,e) A(n,f) A(n,g)
#define A8(n,a, b, c, d, e, f, g, h) A(n,a) A(n,b) A(n,c) A(n,d) A(n,e) A(n,f) A(n,g) A(n,h)
#define A9(n,a, b, c, d, e, f, g, h,i) A(n,a) A(n,b) A(n,c) A(n,d) A(n,e) A(n,f) A(n,g) A(n,h)A(n,i)
#define A10(n,a, b, c, d, e, f, g, h,i,j) A(n,a) A(n,b) A(n,c) A(n,d) A(n,e) A(n,f) A(n,g) A(n,h)A(n,i)A(n,j)
#define A11(n,a, b, c, d, e, f, g, h,i,j,k) A(n,a) A(n,b) A(n,c) A(n,d) A(n,e) A(n,f) A(n,g) A(n,h)A(n,i)A(n,j)A(n,k)
#define A12(n,a, b, c, d, e, f, g, h,i,j,k,l) A(n,a) A(n,b) A(n,c) A(n,d) A(n,e) A(n,f) A(n,g) A(n,h)A(n,i)A(n,j)A(n,k)A(n,l)
#define A13(n,a, b, c, d, e, f, g, h,i,j,k,l,m) A(n,a) A(n,b) A(n,c) A(n,d) A(n,e) A(n,f) A(n,g) A(n,h)A(n,i)A(n,j)A(n,k)A(n,l)A(n,m)
