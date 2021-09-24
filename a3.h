/*
               init                           next
   ...........................................................
        α|              |ρ      .             fXXe
     ο - 0123456789abcdef - σ   .             dXXc
         XXXXXXXXXXXXXXXX       .           α|    |ρ  
         rsp - fXXe             .   ο - 0123456789abcdef - σ  
               dXXc             .       XXXXXXXXXXXXXXXX
               bXXa             .       rsp - bXXa
               9XX8             .             9XX8
               7XX6             .             7XX6
               5XX4             .             5XX4
               3XX2             .             3XX2
               1XX0             .             1XX0
                    abo <= aba <= obr <= rbs
*/
#pragma once
#pragma clang diagnostic ignored "-Wmultichar"
typedef struct p_s {
  union {
    void (*c)(struct p_s *, long, long, struct p_s *);
    void *v;
    char b;
    short w;
    int d;
    long q;
    unsigned char B;
    unsigned short W;
    unsigned int D;
    unsigned long Q;
  };
} p_t;
typedef void (*n_t)(p_t *, long, long, p_t *);
#define N(n) void n(p_t *ο, long α, long ρ, p_t *σ)
#define T(n) n##ο, n##α, n##ρ, n##σ
#define R(T,n) T n = (T)ο[--α].v;
#define Rpith(n)\
  p_t * n##σ = ο[--α].v;\
  long  n##ρ = n##σ[0].q
#define C(n,r) n##σ[n##ρ + r].c(ο, α, n##ρ, n##σ)
#define O ο[α - 1].c(ο, α - 1, ρ, σ)
#define A(a) ο[α++].v = (void*)a,
/*
console.log(
  Array(21).fill()
           .map((_, a) => String.fromCharCode(a+0x61))
           .map((v, i, a) => `#define A${i}(${a.slice(0,i)}) ${a.slice(0,i).map(v=>`A(${v})`).join('')}`)
           .slice(2)
           .join('\n')
)
*/
#define A2(a,b) A(a)A(b)
#define A3(a,b,c) A(a)A(b)A(c)
#define A4(a,b,c,d) A(a)A(b)A(c)A(d)
#define A5(a,b,c,d,e) A(a)A(b)A(c)A(d)A(e)
#define A6(a,b,c,d,e,f) A(a)A(b)A(c)A(d)A(e)A(f)
#define A7(a,b,c,d,e,f,g) A(a)A(b)A(c)A(d)A(e)A(f)A(g)
#define A8(a,b,c,d,e,f,g,h) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)
#define A9(a,b,c,d,e,f,g,h,i) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)
#define A10(a,b,c,d,e,f,g,h,i,j) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)
#define A11(a,b,c,d,e,f,g,h,i,j,k) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)
#define A12(a,b,c,d,e,f,g,h,i,j,k,l) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)
#define A13(a,b,c,d,e,f,g,h,i,j,k,l,m) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)
#define A14(a,b,c,d,e,f,g,h,i,j,k,l,m,n) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)
#define A15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)
#define A16(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)
#define A17(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)
#define A18(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)
#define A19(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)
#define A20(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)A(t)
N(da);N(daa);N(aradani);
#ifdef STATIC
static N(da_an) {
  ρ += 4;
  C(, 0);
}
static N(da_da) {
  ρ += 3;
  n_t n = σ[ρ++].c;
  n(T());
}
N(da) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = da_da;
  σ[--ρ].c = da_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(daa_an) {
  ρ += 5;
  C(, 0);
}
static N(daa_da) {
  ρ += 3;
  ο[α++].v = σ[ρ++].v;
  n_t n = σ[ρ++].c;
  n(T());
}
N(daa) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = daa_da;
  σ[--ρ].c = daa_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(aradani_ara) {
  ρ += 6;
  n_t n = σ[ρ - 3].c;
  n(T());
}
static N(aradani_da) {
  ρ += 6;
  n_t n = σ[ρ - 2].c;
  n(T());
}
static N(aradani_an) {
  ρ += 6;
  n_t n = σ[ρ - 1].c;
  n(T());
}
N(aradani) {
  σ[--ρ].c = ο[--α].c; // an
  σ[--ρ].c = ο[--α].c; // da
  σ[--ρ].c = ο[--α].c; // ara
  σ[--ρ].c = aradani_ara;
  σ[--ρ].c = aradani_da;
  σ[--ρ].c = aradani_an;
  n_t sgadasabmeli = ο[--α].c;
  sgadasabmeli(T());
}
#endif
