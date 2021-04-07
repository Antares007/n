#define FIRST_(a, ...) a
#define SECOND_(a, b, ...) b

#define FIRST(...) FIRST_(__VA_ARGS__, )
#define SECOND(...) SECOND_(__VA_ARGS__, )

#define EMPTY()

#define EVAL(...) EVAL1024(__VA_ARGS__)
#define EVAL1024(...) EVAL512(EVAL512(__VA_ARGS__))
#define EVAL512(...) EVAL256(EVAL256(__VA_ARGS__))
#define EVAL256(...) EVAL128(EVAL128(__VA_ARGS__))
#define EVAL128(...) EVAL64(EVAL64(__VA_ARGS__))
#define EVAL64(...) EVAL32(EVAL32(__VA_ARGS__))
#define EVAL32(...) EVAL16(EVAL16(__VA_ARGS__))
#define EVAL16(...) EVAL8(EVAL8(__VA_ARGS__))
#define EVAL8(...) EVAL4(EVAL4(__VA_ARGS__))
#define EVAL4(...) EVAL2(EVAL2(__VA_ARGS__))
#define EVAL2(...) EVAL1(EVAL1(__VA_ARGS__))
#define EVAL1(...) __VA_ARGS__

#define DEFER1(m) m EMPTY()
#define DEFER2(m) m EMPTY EMPTY()()

#define IS_PROBE(...) SECOND(__VA_ARGS__, 0)
#define PROBE() ~, 1

#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)

#define NOT(x) IS_PROBE(CAT(_NOT_, x))
#define _NOT_0 PROBE()

#define BOOL(x) NOT(NOT(x))

#define IF_ELSE(condition) _IF_ELSE(BOOL(condition))
#define _IF_ELSE(condition) CAT(_IF_, condition)

#define _IF_1(...) __VA_ARGS__ _IF_1_ELSE
#define _IF_0(...) _IF_0_ELSE

#define _IF_1_ELSE(...)
#define _IF_0_ELSE(...) __VA_ARGS__

#define HAS_ARGS(...) BOOL(FIRST(_END_OF_ARGUMENTS_ __VA_ARGS__)())
#define _END_OF_ARGUMENTS_() 0

#define MAP(m, first, ...)                                                     \
  m(first) IF_ELSE(HAS_ARGS(__VA_ARGS__))(                                     \
      DEFER2(_MAP)()(m, __VA_ARGS__))(/* Do nothing, just terminate */         \
  )
#define _MAP() MAP

#define apply_(X) PUSH(X)
#define apply(...) EVAL(MAP(apply_, __VA_ARGS__))

#define LPAREN (
#define RPAREN )
#define COMMA ,

#define EXPAND(...) __VA_ARGS__

#define SPLIT(OP, D) EXPAND(OP CAT(SPLIT_, D) RPAREN)

#define SPLIT_int LPAREN int COMMA
#define SPLIT_char LPAREN char COMMA
#define SPLIT_float LPAREN float COMMA
#define SPLIT_double LPAREN double COMMA

#define MY_MACRO(A, B)                                                         \
  SPLIT(MY_OTHER_MACRO, A);                                                    \
  SPLIT(MY_OTHER_MACRO, B);

#define PUSH(v)                                                                \
  _Generic((v), int : pushint, float : pushfloat, default : pushvoidptr)(α, v);
#define MPUSH(n, T)                                                            \
  static void n(void **advance, T v) {                                         \
    *(T *)*advance = v;                                                        \
    *(char **)advance += sizeof(T);                                            \
  }
MPUSH(pushint, int)
MPUSH(pushfloat, float)
MPUSH(pushvoidptr, void *)

#define N(n) void n(struct cpith *o, void **α)
#define P(...)
#define Cm(m, o, ...)                                                          \
  {                                                                            \
    void *β = *α;                                                              \
    apply(__VA_ARGS__);                                                        \
    o->m(o, α);                                                                \
    *α = β;                                                                    \
  }
#define Rm(m, o, ...)                                                          \
  apply(__VA_ARGS__);                                                          \
  return o->m(o, α);

struct cpith {
  N((*value));
  N((*error));
};

N(counter) { Cm(value, o, "+", 1); }

int main(void) {
  long int value = 3;
  void *ptr = &value;
  void **α = &ptr;
  apply();
  return (long int)*α;
}
