CC=clang
CFLAGS=-std=c99 -g -Wall -Wno-multichar -Wno-unused-function $(UFLAGS)

.PHONY: clean 
g4: g4.c
	${CC} $< -o $@ -luv -lpthread
g3: g3.c
	${CC} $< -o $@ -luv -lpthread
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


