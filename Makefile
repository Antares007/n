CC=clang
CFLAGS=-std=c99 -g -Wall -Wno-multichar $(UFLAGS)

.PHONY: clean 

mb.o: mb.h an.h
cb.o: mb.h an.h 
cb: mb.o cb.o 
%.dump: %.o
	objdump -d -Mintel $<
clean:
	git clean -xdf


