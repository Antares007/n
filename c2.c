#include "a3.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

N(akhali_purtseli) { A(0) σ[-1].c(T()); }
N(akhali_gulguli) { A(1) σ[-1].c(T()); }
N(amotsere) { A(2) σ[-1].c(T()); }
N(tsertili) { A(3) σ[-1].c(T()); }
N(shemdegi) { A(4) σ[-1].c(T()); }

N(test) { C(, 1); }

N(an_gadasvla) { C(, 0); }
N(da_gadasvla) { C(, 1); }
N(sss) {
  R(n_t, nar);
  R(unsigned long, c);
  R(p_t *, kalapoti);
  A12(σ, c + 1, nar, akhali_purtseli, 4, amotsere, daa, kalapoti, tsertili, daa,
      shemdegi, da)
  O;
}
N(tskaro0) { A2(an_gadasvla, sss) O; }
N(tskaro1) {
  if (ο[α - 1].Q % 1000000 == 0)
    printf("%s, c: %ld\n", (char *)ο[α - 3].v, ο[α - 1].q);
  A2(da_gadasvla, sss) O;
}
N(tskaro2) {}
N(kalapoti0) { A2(da_gadasvla, sss) O; }
N(kalapoti1) {
  if (ο[α - 1].Q % 1000000 == 0)
    printf("c: %ld\n", ο[α - 1].q);
  A2(da_gadasvla, sss) O;
}
N(kalapoti2) {}
N(tskaros_gulguli) {
  A9(tskaro0, tskaro1, tskaro2, 3, 6, 9, σ[-1].c, 7, akhali_gulguli) O;
}
N(kalapotis_gulguli) {
  A9(kalapoti0, kalapoti1, kalapoti2, 3, 9, 6, σ[-1].c, 7, akhali_gulguli) O;
}
N(exam) {
  A12(kalapotis_gulguli, -2, an_gadasvla, akhali_purtseli, daaa, 4, amotsere,
      daa, tskaros_gulguli, da, tsertili, da)
  O;
}
N(tsinamkhare) {
  // A8("პირველი", exam, "მეორე", exam, daa, "მესამე", exam, daa) O;
  // A5("პირველი", exam, "მეორე", exam, daa) O;
  A2("პირველი", exam) O;
}

#include "page.h"
#define ISPAGE(lx)                                                             \
  ((unsigned long)lx & (unsigned long)0xFFF) == 3 * sizeof(void *)
#define PS(p) (void *)((unsigned long)p & ~((unsigned long)0xFFF))
#define PN(p) (PS(p) + 0x1000)
N(os_akhali_purtseli) {
  // printf("%s %ld\n", __FUNCTION__, (((unsigned long)σ) >> 12) - (((unsigned
  // long)σ[1].v) >> 12));
  p_t *lx = σ[1].v;
  p_t *nο = PN(lx);
  nο += 3;
  if (σ < nο)
    return C(, 2);
  nο[-3].v = lx, nο[-2].v = σ, nο[-1].Q = 0;
  lx[-2].v = nο;
  σ[1].v = nο;
  A(nο) C(, 1);
}
N(os_akhali_gulguli) {
  p_t *lx = σ[1].v;
  p_t *nσ = &lx[ISPAGE(lx) ? 506 : 512];
  long pages = (((unsigned long)σ >> 12) - ((unsigned long)nσ >> 12)) / 3;
  //printf("%ld\n", pages);
  nσ = &nσ[pages * 512];
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
#define MAX_RIGIS_ELEMENTI 1024
rigis_elementi_t rigis_elementebi[MAX_RIGIS_ELEMENTI];
QUEUE rigis_tavi;
static void init_rigi() {
  for (int i = 0; i < MAX_RIGIS_ELEMENTI; i++)
    rigis_elementebi[i].q[0] = 0;
  QUEUE_INIT(&rigis_tavi);
}
static int shemdegi_rigis_nomeri() {
  static int last = 0;
  int i;
  for (i = last + 1; i < MAX_RIGIS_ELEMENTI; i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  for (i = 1; i < last; i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  return 0;
}
N(os_tsertili) {
  int nomeri = shemdegi_rigis_nomeri();
  if (nomeri == 0)
    return C(, 2);
  R(p_t *, nσ);
  R(p_t *, nο);
  rigis_elementebi[nomeri].ο = nο;
  rigis_elementebi[nomeri].σ = nσ;
  QUEUE_INSERT_TAIL(&rigis_tavi, &rigis_elementebi[nomeri].q);
  C(, 1);
}
N(os_shemdegi) {
  ο[-1].Q = α;
  if (α == 0 && ο[-3].v != 0) {
    p_t *l = ο[-3].v, *r = ο[-2].v;
    l[ISPAGE(l) ? -2 : 2].v = r;
    r[ISPAGE(r) ? -3 : 1].v = l;
  }
  QUEUE *q;
  if (&rigis_tavi != (q = QUEUE_NEXT(&rigis_tavi))) {
    QUEUE_REMOVE(q);
    rigis_elementi_t *e = (void *)q;
    e->q[0] = 0;
    p_t *eο = e->ο, *eσ = e->σ;
    long eα = eο[-1].q, eρ = eσ[0].q;
    eο[eα - 1].c(eο, eα - 1, eρ, eσ);
  }
}
n_t opcode_map[] = {os_akhali_purtseli, os_akhali_gulguli, os_amotsere,
                    os_tsertili, os_shemdegi};
N(os_opcode) {
  R(unsigned long, opcode);
  opcode_map[opcode](T());
}
int main() {
  init_rigi();
  // |.b..........|............|.e..........|............
  void *b = malloc(100 << 12);
  void *e = b + (100 << 12);
  p_t *ο = (void *)((unsigned long)b | ((unsigned long)0xFFF)) + 1,
      *σ = (void *)((unsigned long)e & ~((unsigned long)0xFFF));
  printf("mem   %p %p\n", b, e);
  printf("grid  %p %p\n", ο, σ);
  printf("pages %ld\n", ((unsigned long)σ >> 12) - ((unsigned long)ο >> 12));
  ο += 3, σ -= 3;
  printf("tree  %p %p\n", ο, σ);

  long α = 0, ρ = 0;

  ο[-3].Q = 0, ο[-2].v = σ, ο[-1].Q = 0;

  σ[--ρ].c = os_opcode;
  σ[--ρ].c = os_shemdegi;
  σ[--ρ].c = os_shemdegi;
  σ[--ρ].c = os_shemdegi;
  σ[0].q = ρ, σ[1].v = ο, σ[2].v = 0;

  tsinamkhare(ο, α, ρ, σ);

  free(b);
}
