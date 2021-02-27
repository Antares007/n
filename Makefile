CC=clang
CFLAGS=-std=c99 -g -Wall -Wno-multichar $(UFLAGS)

.PHONY: clean 


%.dump: %.o
	objdump -d -Mintel $<
clean:
	rm -f minilisp *~


