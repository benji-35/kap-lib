##
## EPITECH PROJECT, 2021
## tests
## File description:
## Makefile
##

C_STANDARD_FLAGS =
C_WARNING_FLAGS = -Wextra -Wall -g
INCLUDE_FLAGS =

C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

GCC = gcc

INCLUDE_FLAGS += -I ../kap-lib/include

LIB_FLAGS += -L ../kap-lib -lkap -lcriterion

SRC                 =   kprintf_tests.c	\
						kstr_tests.c	\
						kmath_tests.c

SRC_MAIN	=	main.c

OBJ = $(SRC:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

all: build_sub tests main-parser
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

main-parser:	$(OBJ_MAIN)
	@$(GCC) -o $@ $(OBJ_MAIN) $(LIB_FLAGS)
	@rm -f $(OBJ_MAIN)

fclean: clean
	@find . -type f -name 'vgcore*' -delete
	@rm -rf tests tests.dSYM
.PHONY : fclean

re: fclean all
.PHONY : re