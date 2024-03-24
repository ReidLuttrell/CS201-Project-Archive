# NOTE: All indented lines are indented with a tab character.

.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -no-pie
DFLAGS = -g

all: hw3 hw3crc hw3cmov

hw3: hw3.o crc.o
	gcc -g -o hw3 $(CFLAGS) $(DFLAGS) hw3.o crc.o
	
hw3.o: hw3.c
	gcc -c -g -o hw3.o $(CFLAGS) $(DFLAGS) hw3.c

crc.o: crc.c
	gcc -c -g -o crc.o $(CFLAGS) $(DFLAGS) crc.c

hw3crc: hw3crc.o crc.o; gcc -g -o hw3crc $(CFLAGS) $(DFLAGS) hw3crc.o hw3.o

hw3crc.o: hw3crc.s; as --64 -o hw3crc.o hw3crc.s

hw3cmov: hw3cmov.o crc.o; gcc -g -o hw3cmov $(CFLAGS) $(DFLAGS) hw3cmov.o hw3.o

hw3cmov.o: hw3cmov.s; as --64 -o hw3cmov.o hw3cmov.s

clean:
	rm -f *.o hw3 hw3crc hw3cmov

zip:
	zip rename_me.zip Makefile hw3.c crc.c hw3crc.s hw3cmov.s typescript
