##
## EPITECH PROJECT, 2021
## tests
## File description:
## Makefile
##

C_STANDARD_FLAGS =
C_WARNING_FLAGS = -Wextra -Wall
INCLUDE_FLAGS =

C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

GCC = gcc

INCLUDE_FLAGS += -I ../kap-lib/include

LIB_FLAGS += -L ../kap-lib -lkap -lcriterion

SRC                 =   main.c

OBJ = $(SRC:.c=.o)

all: build_sub tests
.PHONY : all

build_sub:
	@make -sC ../kap-lib

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

clean:
	@find . \( -name "*.o" -o -name "*.a" \) -delete
.PHONY : clean

tests: $(OBJ)
	@$(GCC) -o $@ $(OBJ) $(LIB_FLAGS)
	@rm -f $(OBJ)

fclean: clean
	@find . -type f -name 'vgcore*' -delete
	@rm -rf tests tests.dSYM
.PHONY : fclean

re: fclean all
.PHONY : re