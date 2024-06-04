CC=gcc

LFLAGS=
CFLAGS=-Wall -Werror -Wextra -c -pedantic -g -lcheck

ODIR = obj/
MAIN_C = test_s21_string.c
UTILS_C = s21_string.c
MAIN_H = s21_string.h
MAIN_O = $(MAIN_C:%.c=$(ODIR)%.o)
UTILS_O = $(UTILS_C:%.c=$(ODIR)%.o)


all: test_s21
test_s21: $(ODIR) $(MAIN_O) $(UTILS_O)
	$(CC) $(LFLAGS) $(MAIN_O) $(UTILS_O) -o ./test_s21
$(ODIR):
	@mkdir -p $(ODIR)
	@echo "folder: $(GREEN)$(ODIR) was created$(RESET)"

$(MAIN_O): $(MAIN_C) $(MAIN_H)
	$(CC) $(CFLAGS) -o $@ $<
$(UTILS_O): $(UTILS_C) $(MAIN_H)
	$(CC) $(CFLAGS) -o $@ $<

clang:
	clang-format -i $(MAIN_C) $(UTILS_C) $(MAIN_H)

clean:
	rm -rf $(ODIR)*.o
	rm -rf ./test_s21