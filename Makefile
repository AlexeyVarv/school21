CC=gcc

LFLAGS=-lcheck -lm -lsubunit -lrt -lpthread -lgcov
CFLAGS=-Wall -Werror -Wextra -c -pedantic -g -std=c11
CFLAGSG=-Wall -Werror -Wextra -c -pedantic -g -std=c11 -fprofile-arcs -ftest-coverage

ODIR = obj/
MAIN_C = test_s21_string.c
UTILS_C = s21_string.c
MAIN_H = s21_string.h
TEST_C = simple_test_s21_string.c
MAIN_O = $(MAIN_C:%.c=$(ODIR)%.o)
UTILS_O = $(UTILS_C:%.c=$(ODIR)%.o)
TEST_O = $(TEST_C:%.c=$(ODIR)%.o)


all: test_s21
test_s21: $(ODIR) $(MAIN_O) $(UTILS_O)
	$(CC) $(MAIN_O) $(UTILS_O) $(LFLAGS) -o ./test_s21
$(ODIR):
	@mkdir -p $(ODIR)
	@echo "folder: $(GREEN)$(ODIR) was created$(RESET)"

$(MAIN_O): $(MAIN_C) $(MAIN_H)
	$(CC) $(CFLAGS) -o $@ $<
$(UTILS_O): $(UTILS_C) $(MAIN_H)
	$(CC) $(CFLAGSG) -o $@ $<
$(TEST_O): $(TEST_C) $(MAIN_H)
	$(CC) $(CFLAGS) -o $@ $<

test: simple_test
simple_test: $(ODIR) $(TEST_O) $(UTILS_O)
	$(CC) $(TEST_O) $(UTILS_O) $(LFLAGS) -o ./simple_test

gcov_report:
	gcovr -r $(ODIR) -f my_program/string_project/s21_string.c --html --html-details -o covarege_report.html	

clang:
	clang-format -i $(MAIN_C) $(UTILS_C) $(MAIN_H)

clean:
	rm -rf $(ODIR)*.o $(ODIR)*.gcda $(ODIR)*.gcno
	rm -rf ./test_s21 ./simple_test

.PHONY: test_s21 simple_test
