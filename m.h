typedef void (*n_t)(void **β, long α, long ρ, long σ);
#define N(n) void(n)(void **β, long α, long ρ, long σ)
#define S(n) static N(n)
#define Rc(n)                                                                  \
  long n##σ = (long)β[--α];                                                    \
  long n##ρ = (long)β[--α];                                                    \
  long n##α = (long)β[--α];                                                    \
  void **n##β = β[--α]
#define O(n, ...)                                                              \
  do {                                                                         \
    void **_ω = n##β;                                                          \
    long _α = n##α;                                                            \
    long _ρ = n##ρ;                                                            \
    long _σ = n##σ;                                                            \
    void **β = _ω;                                                             \
    long α = _α;                                                               \
    long ρ = _ρ;                                                               \
    long σ = _σ;                                                               \
    __VA_ARGS__((n_t *)β)[α - 1](β, α - 1, ρ, σ);                              \
  } while (0)

