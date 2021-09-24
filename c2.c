#include "a3.h"
#include <stdio.h>
#include <stdlib.h>

N(akhali_purtseli) { A(0) σ[-1].c(T()); }
N(akhali_gulguli) { A(1) σ[-1].c(T()); }
N(amotsere) { A(2) σ[-1].c(T()); }
N(tsertili) { A(3) σ[-1].c(T()); }
N(shemdegi) { A(4) σ[-1].c(T()); }

N(test) { C(, 1); }

N(an_gadasvla) { C(, 0); }
N(os_gadamkvani) {
  p_t *osσ = σ[-2].v;
  (osσ[-1].c(ο, α, osσ[0].q, osσ));
}
N(i0) { printf("i0\n"); }
N(i1) { printf("i1\n"); }
N(i2) { printf("i2\n"); }
N(tskaros_gulguli) {
  A9(i0, i1, i2, 3, 6, σ, os_gadamkvani, 7, akhali_gulguli) O;
}
N(kalapotis_gulguli) {
  A9(i0, i1, i2, 3, 6, σ, os_gadamkvani, 7, akhali_gulguli) O;
}
N(tsinamkhare) {
  A11(kalapotis_gulguli, an_gadasvla, akhali_purtseli, daa, 2, amotsere, daa,
      tskaros_gulguli, da, tsertili, da)
  O;
  // A3(akhali_purtseli, test, da) O;
  // A5(akhali_purtseli, akhali_purtseli, da, tskaros_gulguli, da) O;
}

#include "page.h"
#define ISPAGE(lx)                                                             \
  ((unsigned long)lx & (unsigned long)0xFFF) == 3 * sizeof(void *)
N(os_akhali_purtseli) {
  p_t *lx = σ[1].v;
  p_t *nο = &lx[ISPAGE(lx) ? 512 : 6];
  if (σ < nο)
    return C(, 2);
  nο[-3].v = lx, nο[-2].v = σ, nο[-1].Q = 0;
  lx[-2].v = nο;
  σ[1].v = nο;
  A(nο) C(, 1);
}
N(os_akhali_gulguli) {
  p_t *lx = σ[1].v;
  p_t *begin = &lx[ISPAGE(lx) ? -3 : 3];
  long pages = (((unsigned long)σ >> 12) - ((unsigned long)begin >> 12)) / 2;
  p_t *nσ = &begin[pages * 512 + 512 - 3];
  long nρ = 0;
  R(unsigned long, wc);
  while (wc--)
    nσ[--nρ].v = ο[--α].v;
  nσ[0].q = nρ, nσ[1].v = lx, nσ[2].v = σ;
  lx[-2].v = nσ;
  σ[1].v = nσ;
  A(nσ) C(, 1);
}
N(os_amotsere) {
  R(unsigned long, wc);
  R(p_t *, pο);
  long pα = (pο[-1].q = pο[-1].q + wc);
  for (long i = 1; i <= wc; i++)
    pο[pα - i].v = ο[--α].v;
  A(pο) C(, 1);
}
#include "src/queue.h"
typedef struct {
  QUEUE q;
  p_t *ο;
  p_t *σ;
} rigis_elementi_t;
#define PROCESS_MAX_PID 1024
static int process_allocate_pid(rigis_elementi_t *arr) {
  static int last = 0;
  int i;
  for (i = last + 1; i < PROCESS_MAX_PID; i++)
    if (arr[i].q[0] == 0)
      return last = i, i;
  for (i = 1; i < last; i++)
    if (arr[i].q[0] == 0)
      return last = i, i;
  return 0;
}
N(os_tsertili) {
  rigis_elementi_t *elms = (void *)&σ[-3 - PROCESS_MAX_PID * sizeof(rigis_elementi_t)/sizeof(void*)];
  int pid = process_allocate_pid(elms);
  if (pid == 0)
    return C(, 2);
  rigis_elementi_t *e = &elms[pid];
  R(p_t *, nσ);
  R(p_t *, nο);
  e->ο = nο;
  e->σ = nσ;
  QUEUE_INSERT_TAIL((QUEUE *)&σ[-3], &e->q);
  C(, 1);
}
N(os_shemdegi) {
  ο[-1].Q = α;
  QUEUE *q;
  if ((QUEUE *)&σ[-3] != (q = QUEUE_NEXT((QUEUE *)&σ[-3]))) {
    QUEUE_REMOVE(q);
    rigis_elementi_t *e = (void *)q;
    e->q[0]=0;
    p_t *eο = e->ο, *eσ = e->σ;
    long eα = eο[-1].q, eρ = eσ[0].q;
    eο[eα - 1].c(eο, eα - 1, eρ, eσ);
  }
}
n_t opcodes[] = {os_akhali_purtseli, os_akhali_gulguli, os_amotsere,
                 os_tsertili, os_shemdegi};
N(os) {
  R(unsigned long, opcode);
  opcodes[opcode](T());
}
N(o0) { printf("o0\n"), os_shemdegi(T()); }
N(o1) { printf("o1\n"), os_shemdegi(T()); }
N(o2) { printf("o2\n"), os_shemdegi(T()); }

// ....|x...dddd..............oans|.......
page_t *pith_init(void *begin, unsigned long length, unsigned long page_bits) {
  page_init(begin + 0x20, begin, length, page_bits);
  return begin + 0x20;
}
int main() {
  // |.b..........|............|.e..........|............
  //
  void *b = malloc(100 << 12);
  void *e = b + (100 << 12);
  p_t *ο = (void *)((unsigned long)b |  ((unsigned long)0xFFF)) + 1,
      *σ = (void *)((unsigned long)e & ~((unsigned long)0xFFF));
  printf("mem   %p %p\n", b, e);
  printf("grid  %p %p\n", ο, σ);
  printf("pages %ld\n", ((unsigned long)σ>>12)-((unsigned long)ο>>12));
  long α = 0, ρ = 0;
  ο+=3, σ-=3;
  printf("tree  %p %p\n", ο, σ);
  ο[-3].Q = 0, ο[-2].v = σ, ο[-1].Q = 0;

  σ[--ρ].c = os;
  σ[--ρ].v = 0;
  σ[--ρ].v = 0;
  rigis_elementi_t *elms = (void *)&σ[ρ -= PROCESS_MAX_PID * sizeof(rigis_elementi_t) / sizeof(void *)];
  for (int i = 0; i < PROCESS_MAX_PID; i++)
    elms[i].q[0] = 0;
  σ[--ρ].c = o2;
  σ[--ρ].c = o1;
  σ[--ρ].c = o0;
  σ[0].q = ρ, σ[1].v = ο, σ[2].v = 0;

  QUEUE_INIT((QUEUE *)&σ[-3]);

  tsinamkhare(ο, α, ρ, σ);

  free(b);
}
