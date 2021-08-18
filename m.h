typedef void (*n_t)(void **ο, long α, long ρ, long σ);
#define N(n) void(n)(void **ο, long α, long ρ, long σ)
#define S(n) static N(n)
#define O(n, ...)                                                              \
  do {                                                                         \
    void **_ο = n##ο;                                                          \
    long _α = n##α, _ρ = n##ρ, _σ = n##σ;                                      \
    void **ο = _ο;                                                             \
    long α = _α, ρ = _ρ, σ = _σ;                                               \
    __VA_ARGS__((n_t *)ο)[α - 1](ο, α - 1, ρ, σ);                              \
  } while (0)
