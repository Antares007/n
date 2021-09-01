#pragma clang diagnostic ignored "-Wmultichar"
#include <stdio.h>
#include <stdlib.h>
typedef struct p_s {
  union {
    void (*c)(struct p_s *o);
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
typedef void (*n_t)(p_t *);
#define α [-1].Q
#define ρ [-2].Q
#define σ [-3].Q
void add(p_t *o) {
  long l = o[--o α].q;
  long r = o[--o α].q;
  o[o α++].q = l + r;
  o[o ρ + 1].c(o);
}
#include <stdio.h>
#include <stdlib.h>
void nar(p_t *o) { o α++; }

int main() {
  p_t *c = malloc(512 * sizeof(void *));
  p_t *o = c + 5;
  o α = 0;
  o ρ = 512;
  o σ = 512;
  o[-4].Q = 0;
  o[-5].Q = 0;
  nar(o);
  free(c);
}
