##
## EPITECH PROJECT, 2021
## kap-lib
## File description:
## Makefile
##

PATH_STR =	kap/kapstr/

PATH_UTILS =	kap/kutils/

PATH_PRINTF =	kap/kapprintf/

PATH_MATHS =	kap/kmaths/

SRC_KAP =	

SRC_KSTR =	$(PATH_STR)concat_str.c			\
			$(PATH_STR)contain_str.c		\
			$(PATH_STR)equal_str.c			\
			$(PATH_STR)finish_with.c		\
			$(PATH_STR)lenght_str.c			\
			$(PATH_STR)split_str.c			\
			$(PATH_STR)start_with.c			\
			$(PATH_STR)str_to_lowercase.c	\
			$(PATH_STR)copy_str.c			\
			$(PATH_STR)int_to_str.c			\
			$(PATH_STR)str_to_int.c			\
			$(PATH_STR)str_get_words.c		\
			$(PATH_STR)inverse_str.c		\
			$(PATH_STR)insert_char_str.c	\
			$(PATH_STR)free_split.c			\
			$(PATH_STR)nb_char_occur.c		\
			$(PATH_STR)remove_first_char.c	\
			$(PATH_STR)char_is_an.c			\
			$(PATH_STR)empty_str.c			\
			$(PATH_STR)double_to_str.c		\
			$(PATH_STR)str_to_double.c		\
			$(PATH_STR)add_line_text.c		\
			$(PATH_STR)remove_line_text.c	\
			$(PATH_STR)add_char_str.c		\
			$(PATH_STR)remove_str_text.c	\
			$(PATH_STR)replace_str_char.c	\
			$(PATH_STR)split_to_str.c		\
			$(PATH_STR)insert_str_str.c		\
			$(PATH_STR)my_putstr.c			\
			$(PATH_STR)split_str_str.c		\
			$(PATH_STR)kap_putchar.c		\
			$(PATH_STR)split_str_interv.c

SRC_KUTILS =	$(PATH_UTILS)kan_open_file.c	\
				$(PATH_UTILS)kfree.c			\
				$(PATH_UTILS)kopen_file.c		\
				$(PATH_UTILS)kwrite_file.c

SRC_KPRINTF =	$(PATH_PRINTF)check_flag.c				\
				$(PATH_PRINTF)display_base.c			\
				$(PATH_PRINTF)display_float.c			\
				$(PATH_PRINTF)display_int.c				\
				$(PATH_PRINTF)display_long.c			\
				$(PATH_PRINTF)int_to_binary.c			\
				$(PATH_PRINTF)int_to_hex.c				\
				$(PATH_PRINTF)kaprintf_listing_flag.c	\
				$(PATH_PRINTF)kaprintf.c

SRC_MATHS =	$(PATH_MATHS)kdivisible_by.c	\
			$(PATH_MATHS)kpower.c			\
			$(PATH_MATHS)ksquare_root.c

SRC_KAP += $(SRC_KSTR)
SRC_KAP += $(SRC_KUTILS)
SRC_KAP += $(SRC_MATHS)
SRC_KAP += $(SRC_KPRINTF)

OBJ_KAP = $(SRC_KAP:.c=.o)

GCC = gcc

C_WARNING_FLAGS = -Wextra -Wall

INCLUDE_FLAGS = -I ./include

C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

all: $(OBJ_KAP)
	@ar rc libkap.a $(OBJ_KAP)
	rm -f $(OBJ_KAP)

.PHONY : all

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete

.PHONY : clean