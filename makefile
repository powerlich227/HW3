CFLAGS = -g3 -O0
LIBS = -lm
CC = gcc

all:	func1 func2

runga_kutta.o:	runga_kutta.c runga_kutta.h
	$(CC) $(CFLAGS) -c -o runga_kutta.o runga_kutta.c

func1.o:	func1.c runga_kutta.h
	$(CC) $(CFLAGS) -c -o func1.o func1.c

func2.o:	func2.c runga_kutta.h
	$(CC) $(CFLAGS) -c -o func2.o func2.c

in the file hmwk3.o:	in the file hmwk3.c runga_kutta.h
	$(CC) $(CFLAGS) -c -o in the file hmwk3.o in the file hmwk3.c


in the file hmwk3:	in the file hmwk3.o runga_kutta.o func1.o func2.o
	$(CC) $(CFLAGS) $(LIBS) -o func1.o func2.o runga_kutta.o inthe file hmw3.o

clean:
	rm -f *.o func1 func2
