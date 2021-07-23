CC=clang
WFLAGS=-Wall -Wno-multichar -Wno-unused-function
CFLAGS=-std=gnu99 -g ${WFLAGS}
UV=../libuv/build/libuv_a.a
UVFLAGS=-lutil -lpthread -ldl -lrt

.PHONY: clean 
g%: g%.c mbo.o
	@${CC} $^ -o $@ ${CFLAGS} ${UV} ${UVFLAGS}
%.o: %.c
	@${CC} -c $^ -o $@ ${CFLAGS}
main: main.c
	@${CC} $< -o $@ -O3 -Wno-multichar  /usr/lib/libraylib.so  -lraylib
pith: pith.c pith.h
	@${CC} $< -o $@ -O3 -Wno-multichar
gui: gui.c
	@${CC} $< -o $@ -lX11 -lGL
%.dump: %.o
	@objdump -d -Mintel $<
clean:
	@git clean -xdf


