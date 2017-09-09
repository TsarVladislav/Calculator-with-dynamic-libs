CC = gcc
CFLAGS = -Wall -pedantic -std=c89 -g

all: calculator.o libsum.so libsub.so libmul.so libmdiv.so libfactorial.so
	${CC} calculator.o -o calculator -ldl -rdynamic
#	${CC} calculator.o -o calculator -Llib -lsum -lsub -lmul -ldiv -lfactorial -Wl,-rpath,lib
calculator.o: calculator.c
	${CC} ${CFLAGS} -c calculator.c
libsum.so: sum.o
	${CC} -shared -o lib/libsum.so sum.o
libsub.so: sub.o
	${CC} -shared -o lib/libsub.so sub.o
libmul.so: mul.o
	${CC} -shared -o lib/libmul.so mul.o
libmdiv.so: mdiv.o
	${CC} -shared -o lib/libmdiv.so mdiv.o
libfactorial.so: factorial.o
	${CC} -shared -o lib/libfactorial.so factorial.o
sum.o: sum.c
	${CC} ${CFLAGS} -c -fPIC sum.c
sub.o: sub.c
	${CC} ${CFLAGS} -c -fPIC sub.c
mdiv.o: mdiv.c
	${CC} ${CFLAGS} -c -fPIC mdiv.c
mul.o: mul.c
	${CC} ${CFLAGS} -c -fPIC mul.c
factorial.o: factorial.c
	${CC} ${CFLAGS} -c -fPIC factorial.c
clean:
	rm -f *.o lib/* calculator
