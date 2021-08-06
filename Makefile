CC=clang
WFLAGS=-Wall -Werror -Wno-multichar -Wno-pointer-arith
CFLAGS=-std=c99 -Ofast ${WFLAGS}
UV=../libuv/build/libuv_a.a
UVFLAGS=-lutil -lpthread -ldl -lrt

.PHONY: clean 
src/g%: src/g%.c src/mbo.o
	${CC} $^ -o $@ ${CFLAGS} ${UV} ${UVFLAGS}
src/a%: src/a%.c src/aradani.o
	${CC} $^ -o $@ ${CFLAGS} ${UV} ${UVFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
main: main.c
	${CC} $< -o $@ -O3 -Wno-multichar  /usr/lib/libraylib.so  -lraylib
pith: pith.c pith.h
	${CC} $< -o $@ -O3 -Wno-multichar
gui: gui.c
	${CC} $< -o $@ -lX11 -lGL
%.dump: %.o
	objdump -d -Mintel $<
clean:
	git clean -xdf


