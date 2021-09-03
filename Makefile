CC=clang
WFLAGS=-Wall
CFLAGS=-std=c99 -g ${WFLAGS} -Wno-multichar
UV=../libuv/build/libuv_a.a
UVFLAGS=-lutil -lpthread -ldl -lrt

n: n.c a.o
	${CC} $^ -o $@ ${CFLAGS}
main: main.c aradani.o
	${CC} $^ -o $@ ${CFLAGS}
seven: seven.c aradani.o
	${CC} $^ -o $@ ${CFLAGS}
src/a2: src/a2.c src/aradani.o src/atalloc.o
	${CC} $^ -o $@ ${CFLAGS}
src/g%: src/g%.c src/mbo.o src/aradani.o
	${CC} $^ -o $@ ${CFLAGS} ${UV} ${UVFLAGS}
src/a%: src/a%.c src/aradani.o
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
src/main: src/main.c
	${CC} $< -o $@ -O3 -Wno-multichar  /usr/lib/libraylib.so  -lraylib
pith: pith.c pith.h
	${CC} $< -o $@ -O3 -Wno-multichar
gui: gui.c
	${CC} $< -o $@ -lX11 -lGL
%.dump: %.o
	objdump -d -Mintel $<
clean:
	git clean -xdf
.PHONY: clean 


