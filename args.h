#pragma once
#include "evalmap.h"
#include <stdint.h>

#define ARG_int8_t(a) arg(int8_t, a);
#define ARG_int16_t(a) arg(int16_t, a);
#define ARG_int32_t(a) arg(int32_t, a);
#define ARG_int64_t(a) arg(int64_t, a);

#define ARG_uint8_t(a) arg(uint8_t, a);
#define ARG_uint16_t(a) arg(uint16_t, a);
#define ARG_uint32_t(a) arg(uint32_t, a);
#define ARG_uint64_t(a) arg(uint64_t, a);

#define ARG_int(a) arg(int, a);
#define ARG_nt(a) arg(void *, (void*)a);

#define args(T, ...) EVAL(MAP(CAT(ARG_, T), __VA_ARGS__))
