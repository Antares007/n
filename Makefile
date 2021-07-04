CC=clang
CFLAGS=-std=gnu99 -g -Wall -Wno-multichar -Wno-unused-function $(UFLAGS)

.PHONY: clean 
g%: g%.c
	${CC} $< -o $@ ${CFLAGS} ../libuv/build/libuv_a.a -lutil -lpthread -ldl -lrt
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


