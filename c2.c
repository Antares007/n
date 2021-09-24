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
#define RAY                                                                    \
  printf("%s\n", __FUNCTION__);                                                \
  assert(σ[0].q == ρ)
N(sss) {
  R(n_t, nar);
  R(p_t *, kalapoti);
  A11(σ, nar, akhali_purtseli, 2, amotsere, daa, kalapoti, tsertili, daa,
      shemdegi, da)
  O;
}
N(tskaro0) { RAY, A2(an_gadasvla, sss) O; }
N(tskaro1) { RAY, A2(da_gadasvla, sss) O; }
N(tskaro2) { RAY; }
N(kalapoti0) { RAY, A2(da_gadasvla, sss) O; }
N(kalapoti1) { RAY, A2(da_gadasvla, sss) O; }
N(kalapoti2) { RAY; }
N(tskaros_gulguli) {
  A9(tskaro0, tskaro1, tskaro2, 3, 6, 9, σ[-1].c, 7, akhali_gulguli) O;
}
N(kalapotis_gulguli) {
  A9(kalapoti0, kalapoti1, kalapoti2, 3, 9, 6, σ[-1].c, 7, akhali_gulguli) O;
}
N(exam) {
  A11(kalapotis_gulguli, an_gadasvla, akhali_purtseli, daa, 2, amotsere, daa,
      tskaros_gulguli, da, tsertili, da)
  O;
}
N(tsinamkhare) {
  A7(exam, exam, da, exam, da, exam, da) O;
  // A5(exam, exam, da, exam, da) O;
  // A3(exam, exam, da) O;
}

#include "page.h"
#define ISPAGE(lx)                                                             \
  ((unsigned long)lx & (unsigned long)0xFFF) == 3 * sizeof(void *)
#define PS(p) (void *)((unsigned long)p & ~((unsigned long)0xFFF))
#define PN(p) (PS(p) + 0x1000)
N(os_akhali_purtseli) {
  p_t *lx = σ[1].v;
  p_t *nο = PN(lx);
  nο += 3;
  if (σ < nο) {
    printf("ai\n");
    return C(, 2);
  }
  nο[-3].v = lx, nο[-2].v = σ, nο[-1].Q = 0;
  lx[-2].v = nο;
  σ[1].v = nο;
  A(nο) C(, 1);
}

//(p_t *) ο = 0x00007ffff7d76018
//(long) α = 7
//(long) ρ = -34
//(p_t *) σ = 0x00007ffff7dd8fe8
//(p_t *) lx = 0x00007ffff7d76018
//(p_t *) begin = 0x00007ffff7d76000
//(long) pages = 49
//(unsigned long) wc = 7
N(os_akhali_gulguli) {
  p_t *lx = σ[1].v;
  p_t *nσ = &lx[ISPAGE(lx) ? 506 : 512];
  long pages = (((unsigned long)σ >> 12) - ((unsigned long)nσ >> 12)) / 3;
  printf("%ld\n",pages);
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
#define MAX_PID 1024
rigis_elementi_t rigis_elementebi[MAX_PID];
QUEUE queue;
static int process_allocate_pid() {
  static int last = 0;
  int i;
  for (i = last + 1; i < MAX_PID; i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  for (i = 1; i < last; i++)
    if (rigis_elementebi[i].q[0] == 0)
      return last = i, i;
  return 0;
}
N(os_tsertili) {
  int pid = process_allocate_pid();
  if (pid == 0)
    return C(, 2);
  R(p_t *, nσ);
  R(p_t *, nο);
  rigis_elementebi[pid].ο = nο;
  rigis_elementebi[pid].σ = nσ;
  QUEUE_INSERT_TAIL(&queue, &rigis_elementebi[pid].q);
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
  if (&queue != (q = QUEUE_NEXT(&queue))) {
    QUEUE_REMOVE(q);
    rigis_elementi_t *e = (void *)q;
    e->q[0] = 0;
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
N(o0) { RAY, os_shemdegi(T()); }
N(o1) { RAY, os_shemdegi(T()); }
N(o2) { RAY, os_shemdegi(T()); }

int main() {
  for (int i = 0; i < MAX_PID; i++)
    rigis_elementebi[i].q[0] = 0;
  QUEUE_INIT(&queue);
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

  σ[--ρ].c = os;
  σ[--ρ].c = o2;
  σ[--ρ].c = o1;
  σ[--ρ].c = o0;
  σ[0].q = ρ, σ[1].v = ο, σ[2].v = 0;

  tsinamkhare(ο, α, ρ, σ);

  free(b);
}
