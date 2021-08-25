typedef struct c_s {
  void *h;
  struct c_s *t;
} c_t;
typedef struct n_s {
  union {
    void (*c)(struct n_s *, long, long, long);
    void *v;
    long l;
    unsigned long L;
  };
} n_t;

void nar(n_t *o, long a, long r, long s) {
  o[a++].l = 1;
  o[a++].l = 2;
  o[a++].l = 3;
  o[s].c(o, a, r, s);
}
int main() { return sizeof(n_t); }
