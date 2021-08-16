typedef void (*n_t)(void **β, long α, long ρ, long σ);
#define N(n) void(n)(void **β, long α, long ρ, long σ)
#define S(n) static N(n)
#define O(n, ...)                                                              \
  do {                                                                         \
    void **_β = n##β;                                                          \
    long _α = n##α, _ρ = n##ρ, _σ = n##σ;                                      \
    void **β = _β;                                                             \
    long α = _α, ρ = _ρ, σ = _σ;                                               \
    __VA_ARGS__((n_t *)β)[α - 1](β, α - 1, ρ, σ);                              \
  } while (0)
