CC=gcc
CFLAGS= -Wall -g -fprofile-arcs -ftest-coverage

all: tests
tests.o: tests.c
	${CC} -c tests.c -o tests.o ${CFLAGS}
stack.o: stack.c
	${CC} -c stack.c -o stack.o ${CFLAGS}
tests: tests.o stack.o
	${CC} stack.o tests.o -o tests ${CFLAGS}
clean:
	@rm -rf *.o *.gcno *.gcda *.gcov tests 2&>/dev/null
tar:
	tar czvf ../stack.tgz ../stack

