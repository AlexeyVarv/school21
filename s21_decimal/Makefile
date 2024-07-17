CC=gcc

LFLAGS=
CFLAGS=-Wall -Wextra -c -std=c11

ODIR = obj/
MAIN_C = decimal1.c
MATH_C = decimal_math.c
CONVERSE_C = decimal_converse.c
MAIN_H = decimal.h
MAIN_O = $(MAIN_C:%.c=$(ODIR)%.o)
MATH_O = $(MATH_C:%.c=$(ODIR)%.o)
CONVERSE_O = $(CONVERSE_C:%.c=$(ODIR)%.o)

all: s21_decimal
s21_decimal: $(ODIR) $(MAIN_O) $(MATH_O) $(CONVERSE_O)
	$(CC) $(LFLAGS) $(MAIN_O) $(MATH_O) $(CONVERSE_O) -o ./s21_decimal -lm
$(ODIR):
	@mkdir -p $(ODIR)
	@echo "folder: $(GREEN)$(ODIR) was created$(RESET)"

$(MAIN_O): $(MAIN_C) $(MAIN_H)
	$(CC) $(CFLAGS) -o $@ $<
$(MATH_O): $(MATH_C) $(MAIN_H)
	$(CC) $(CFLAGS) -o $@ $<
$(CONVERSE_O): $(CONVERSE_C) $(MAIN_H)
	$(CC) $(CFLAGS) -o $@ $<


clang:
	clang-format -i $(MAIN_C) $(MATH_C) $(MAIN_H)

clean:
	rm -rf $(ODIR)*.o
	rm -rf ./s21_decimal