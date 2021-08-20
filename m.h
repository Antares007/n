typedef void (*n_t)(void **ο, long α, long ρ, long σ);
#define N(n) void(n)(void **ο, long α, long ρ, long σ)
#define S(n) static N(n)
#define Dot(n) ((n_t*)CAT(n,ο))[CAT(n,α)-1](CAT(n,ο),CAT(n,α)-1,CAT(n,ρ),CAT(n,σ));
#define Dos(n) ((n_t*)CAT(n,ο))[CAT(n,σ)+0](CAT(n,ο),CAT(n,α),CAT(n,ρ),CAT(n,σ));
#define C(n,r) ((n_t*)CAT(n,ο))[CAT(n,ρ)+r](CAT(n,ο),CAT(n,α),CAT(n,ρ),CAT(n,σ));
#define O(n, ...)                                                              \
  do {                                                                         \
    void **_ο = n##ο;                                                          \
    long _α = n##α, _ρ = n##ρ, _σ = n##σ;                                      \
    void **ο = _ο;                                                             \
    long α = _α, ρ = _ρ, σ = _σ;                                               \
    __VA_ARGS__((n_t *)ο)[α - 1](ο, α - 1, ρ, σ);                              \
  } while (0)
#define CT(n, s, r, a, o)                                                      \
  unsigned long CAT(n,σ) = s, CAT(n,ρ) = r, CAT(n,α) = a;                      \
  void **CAT(n,ο) = o
#define Nt(n, b, s) CT(n, (unsigned long)s, (unsigned long)s, 0, b)
#define At(n,nt) A(n,CAT(nt,ο))A(n,CAT(nt,α))A(n,CAT(nt,ρ))A(n,CAT(nt,σ))
#define R(nt, T, n) T n = (T)CAT(nt,ο)[--CAT(nt,α)]
#define CAT_(a,b) a##b
#define CAT(a,b) CAT_(a,b)
#define RT(nt, n) R(nt, unsigned long, CAT(n,σ));R(nt, unsigned long, CAT(n,ρ));R(nt, unsigned long, CAT(n,α));R(nt, void**, CAT(n,ο))
#define P(n,a) CAT(n,ο)[--CAT(n,ρ)] = (void *)a,
#define P3(n,a,b,c) P(n,c)P(n,b)P(n,a)
#define D(n) CAT(n,ρ)+=1,
#define D2(n) D(n)D(n)
#define D3(n) D(n)D2(n)
#define D4(n) D(n)D3(n)
#define D5(n) D(n)D4(n)
#define D6(n) D(n)D5(n)
#define U(n) CAT(n,ο)[CAT(n,α)++] = CAT(n,ο)[CAT(n,ρ)++],
#define U2(n) U(n)U(n)
#define U3(n) U(n)U2(n)
#define U4(n) U(n)U3(n)
#define U5(n) U(n)U4(n)
#define U6(n) U(n)U5(n)
#define CH(n) CAT(n, ο)[--CAT(n, ρ)] = CAT(n, ο)[--CAT(n, α)],
#define CH2(n) CH(n) CH(n)
#define CH3(n) CH(n) CH2(n)
#define CH4(n) CH(n) CH3(n)
#define CH5(n) CH(n) CH4(n)
#define CH6(n) CH(n) CH5(n)
#define A(n, a) CAT(n,ο)[CAT(n,α)++] = (void *)a,
//console.log(
//  Array(21).fill()
//  .map((_,a) => String.fromCharCode(a+0x61))
//  .map((v,i,a)=>`#define A${i}(T,${a.slice(0,i)}) ${a.slice(0,i).map(v=>`A(T,${v})`).join('')}`)
//  .slice(2)
//  .join('\n')
//)
#define A2(T,a,b) A(T,a)A(T,b)
#define A3(T,a,b,c) A(T,a)A(T,b)A(T,c)
#define A4(T,a,b,c,d) A(T,a)A(T,b)A(T,c)A(T,d)
#define A5(T,a,b,c,d,e) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)
#define A6(T,a,b,c,d,e,f) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)
#define A7(T,a,b,c,d,e,f,g) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)
#define A8(T,a,b,c,d,e,f,g,h) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)
#define A9(T,a,b,c,d,e,f,g,h,i) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)
#define A10(T,a,b,c,d,e,f,g,h,i,j) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)
#define A11(T,a,b,c,d,e,f,g,h,i,j,k) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)
#define A12(T,a,b,c,d,e,f,g,h,i,j,k,l) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)A(T,l)
#define A13(T,a,b,c,d,e,f,g,h,i,j,k,l,m) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)A(T,l)A(T,m)
#define A14(T,a,b,c,d,e,f,g,h,i,j,k,l,m,n) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)A(T,l)A(T,m)A(T,n)
#define A15(T,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)A(T,l)A(T,m)A(T,n)A(T,o)
#define A16(T,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)A(T,l)A(T,m)A(T,n)A(T,o)A(T,p)
#define A17(T,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)A(T,l)A(T,m)A(T,n)A(T,o)A(T,p)A(T,q)
#define A18(T,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)A(T,l)A(T,m)A(T,n)A(T,o)A(T,p)A(T,q)A(T,r)
#define A19(T,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)A(T,l)A(T,m)A(T,n)A(T,o)A(T,p)A(T,q)A(T,r)A(T,s)
#define A20(T,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)A(T,g)A(T,h)A(T,i)A(T,j)A(T,k)A(T,l)A(T,m)A(T,n)A(T,o)A(T,p)A(T,q)A(T,r)A(T,s)A(T,t)
