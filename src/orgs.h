#pragma once
#include "evalmap.h"
#include "ints.h"

#define ARG_n_t(a) A(n_t, a) 
#define ARG_Q_t(a) A(Q_t, a) 
#define ARG_vs(a) A(void*, (void*)(a)) 
#define An(T, ...) EVAL(MAP(CAT(ARG_, T), __VA_ARGS__))
#define A3(T, a,b,c) A(T,a)A(T,b)A(T,c) 
#define A4(T, a,b,c,d) A(T,a)A(T,b)A(T,c)A(T,d)
#define A5(T, a,b,c,d,e) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)
#define A6(T, a,b,c,d,e,f) A(T,a)A(T,b)A(T,c)A(T,d)A(T,e)A(T,f)
#define მოხსენი R
#define მიადგი A
#define მიადგი3 A3
#define მიადგი4 A4
#define მიადგი5 A5
#define მიადგი6 A6
#define მიადგიn An
#define ჩაახვიე P
#define ჩჩაახვიე PP
#define ჩჩჩაახვიე PPP
#define ჩჩჩჩაახვიე PPPP
#define ამოახვიე U                                                                      
#define აამოახვიე UU
#define ააამოახვიე UUU
#define აააამოახვიე UUUU
#define ამოხიე D 
#define ამოოხიე DD
#define ამოოოხიე DDD
#define ამოოოოხიე DDDD
#define ამოოოოოხიე DDDDD

#define Nar(n, ...)                                                            \
  N(n) { __VA_ARGS__ C; }
#define Sar(n, ...)                                                            \
  S(n) { __VA_ARGS__ C; }
