CC=clang
CFLAGS=-std=c99 -g -Wall -Wno-multichar $(UFLAGS)

.PHONY: clean 

pith: pith.c
	${CC} $^ -o $@ -O3 -Wno-multichar
gui: gui.c
	${CC} $< -o $@ -lX11 -lGL
%.dump: %.o
	objdump -d -Mintel $<
clean:
	git clean -xdf


