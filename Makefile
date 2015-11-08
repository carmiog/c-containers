CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11 -O2
LDFLAGS=
OBJS=vector.o
OBJS_TESTS=vector_unittest.o
.c.o:
	$(CC) $(CFLAGS) -c $<

all: lib
	rm -f *.o

clean:
	rm -f *.a *.o

lib: $(OBJS)
	ar rcs libdatastruc.a $(OBJS)
	
test: lib $(OBJS_TESTS)
	$(CC) $(CFLAGS) -o vector_unittest -L. -ldatastruc vector_unittest.o
