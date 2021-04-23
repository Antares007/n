CC=clang
CFLAGS=-std=c99 -g -Wall -Wno-multichar $(UFLAGS)

.PHONY: clean 

mb.o: mb.h an.h
cb.o: mb.h an.h 
cb: mb.o cb.o 

pith: pith.c
	${CC} $^ -o $@ -O3 -Wno-multichar
nargo: nargo.c mblr.o
	${CC} $^ -o $@ -lX11 -lGL -Wno-multichar
nargoo: nargoo.cpp nargo.h
	clang++ -o $@ $< -std=c++20 
main: main.cpp olc3.h
	clang++ -o $@ $< -lX11 -lGL -lpthread -lpng -O3 -std=c++20 
main.debug: main.cpp olc3.h
	clang++ -o $@ $< -lX11 -lGL -lpthread -lpng -O0 -g -std=c++20 
gui: gui.c
	${CC} $< -o $@ -lX11 -lGL
%.dump: %.o
	objdump -d -Mintel $<
clean:
	git clean -xdf


