CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE #-g -fsanitize=address
CCOV = -fprofile-arcs -ftest-coverage
GFLAGS = --coverage
LDFLAGS = -lgcov
TFLAGS = -lcheck -lm -lpthread

all: clean check test gcov_report

clean:
	rm -rf *.o *.a *.css *.html *.gcno *.gcda *.out *.info tests ./test.* CPPLINT.cfg 

s21_math.o: s21_math.c
	$(CC) $(CFLAGS) -c s21_math.c 

s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a

s21_math_test.o: s21_math_test.c
	$(CC) -c s21_math_test.c

test: s21_math.a s21_math_test.o
	$(CC) $(CCOV) s21_math_test.o s21_math.a -o tests -lcheck
	./tests

gcov_report: s21_math.a
	$(CC) $(GFLAGS) s21_math_test.c s21_math.c s21_math.a -L. s21_math.a $(TFLAGS) -o ./s21_math_test.out
	./s21_math_test.out
	lcov -t "s21_math_test" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

check: 
	cppcheck s21_math.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c s21_math.c
	rm -rf ./CPPßLINT.cfg ./CPPLINT.cfg 

