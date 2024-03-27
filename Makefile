FUNCTIONS = functions/*.c s21_math.h
GCC = gcc -Werror -Wall -Wextra
GLFLAGS=--coverage
GCOVFLAGS=-fprofile-arcs -ftest-coverage

all: s21_math.a

s21_math.a: 
	$(GCC) -c $(FUNCTIONS)
	make build_library
	rm -rf *.o

build_library:
	ar rcs s21_math.a *.o

clang:
	clang-format -i ${FUNCTIONS} s21_tests.c

test: s21_math.a
	$(GCC) $(GLFLAGS) $(GCOVFLAGS) s21_tests.c -L. s21_math.a -lcheck -lm -lsubunit -o s21_tests && ./s21_tests

build_object_files:
	$(GCC) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNCTIONS)

gcov_report: clean build_object_files build_library test
	lcov -o tests.info -c -d .  
	genhtml -o gcov tests.info
	open gcov/index.html

clean:
	rm -rf *.o *.gcno *.gcov *.gcda *.a *.info *.gch gcov s21_tests

rebuild:
	make clean
	make