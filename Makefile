CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11 -O2
LDFLAGS=
OBJS=vector.o
.c.o:
	$(CC) $(CFLAGS) -c $<

all: lib
	rm -f *.o

clean:
	rm -f *.a *.o

lib: $(OBJS)
	ar rcs libdatastruc.a $(OBJS)
	
