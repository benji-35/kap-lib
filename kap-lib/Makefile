##
## EPITECH PROJECT, 2021
## kap-lib
## File description:
## Makefile
##

PATH_STR =	kap/kapstr/

PATH_STR_FORM =	$(PATH_STR)utils_format/

PATH_UTILS =	kap/kutils/

PATH_PRINTF =	kap/kapprintf/

PATH_MATHS =	kap/kmaths/

PATH_LIST =	kap/klist/

PATH_HASH_MAP	=	kap/khashmap/

PATH_PARSER_XML	=	kap/kapparser/xml/

PATH_PARSER_YML	=	kap/kapparser/yml/

PATH_PARSER_JSON	=	kap/kapparser/json/

PATH_MEMORY	=	kap/kmem/

SRC_KAP =	

SRC_KSTR =	$(PATH_STR)concat_str.c				\
			$(PATH_STR)contain_str.c			\
			$(PATH_STR)equal_str.c				\
			$(PATH_STR)finish_with.c			\
			$(PATH_STR)lenght_str.c				\
			$(PATH_STR)split_str.c				\
			$(PATH_STR)start_with.c				\
			$(PATH_STR)str_to_lowercase.c		\
			$(PATH_STR)copy_str.c				\
			$(PATH_STR)int_to_str.c				\
			$(PATH_STR)str_to_int.c				\
			$(PATH_STR)str_get_words.c			\
			$(PATH_STR)inverse_str.c			\
			$(PATH_STR)insert_char_str.c		\
			$(PATH_STR)free_split.c				\
			$(PATH_STR)nb_char_occur.c			\
			$(PATH_STR)remove_first_char.c		\
			$(PATH_STR)char_is_an.c				\
			$(PATH_STR)empty_str.c				\
			$(PATH_STR)double_to_str.c			\
			$(PATH_STR)str_to_double.c			\
			$(PATH_STR)add_line_text.c			\
			$(PATH_STR)remove_line_text.c		\
			$(PATH_STR)add_char_str.c			\
			$(PATH_STR)remove_str_text.c		\
			$(PATH_STR)replace_str_char.c		\
			$(PATH_STR)split_to_str.c			\
			$(PATH_STR)insert_str_str.c			\
			$(PATH_STR)my_putstr.c				\
			$(PATH_STR)split_str_str.c			\
			$(PATH_STR)kap_putchar.c			\
			$(PATH_STR)split_str_interv.c		\
			$(PATH_STR)get_cahrstr_pos.c		\
			$(PATH_STR)advanced_split_str.c		\
			$(PATH_STR)string_format.c			\
			$(PATH_STR_FORM)add_istr.c			\
			$(PATH_STR_FORM)flag_str_format.c	\
			$(PATH_STR_FORM)str_flag_list.c		\
			$(PATH_STR)remove_all_fochar.c

SRC_KUTILS =	$(PATH_UTILS)kan_open_file.c		\
				$(PATH_UTILS)kopen_file.c			\
				$(PATH_UTILS)kwrite_file.c			\
				$(PATH_UTILS)check_file_extension.c	\
				$(PATH_UTILS)kassert.c

SRC_KMEM	=	$(PATH_MEMORY)kfree.c			\
				$(PATH_MEMORY)kcalloc.c			\
				$(PATH_MEMORY)kmemecpy.c		\
				$(PATH_MEMORY)kmemset.c			\
				$(PATH_MEMORY)krealloc.c		\
				$(PATH_MEMORY)kmalloc.c

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
			$(PATH_MATHS)ksquare_root.c		\
			$(PATH_MATHS)int_to_bin.c		\
			$(PATH_MATHS)bin_to_int.c		\
			$(PATH_MATHS)int_to_hexa.c		\
			$(PATH_MATHS)hexa_to_int.c

SRC_HASHMAP	=	$(PATH_HASH_MAP)add_node.c			\
				$(PATH_HASH_MAP)create_hashmap.c	\
				$(PATH_HASH_MAP)destroy_hashmap.c	\
				$(PATH_HASH_MAP)find_node.c

SRC_LIST	=	$(PATH_LIST)kinit_list.c	\
				$(PATH_LIST)klist_clear.c	\
				$(PATH_LIST)klist_rm_node.c	\
				$(PATH_LIST)knode_get.c		\
				$(PATH_LIST)list_add_node.c

SRC_PARSER_XML	=

SRC_PARSER_JSON	=

SRC_PARSER_YML	=	$(PATH_PARSER_YML)create_yml_content.c		\
					$(PATH_PARSER_YML)destroy_yml_parser.c		\
					$(PATH_PARSER_YML)find_node_bindentation.c	\
					$(PATH_PARSER_YML)get_value_yml.c			\
					$(PATH_PARSER_YML)init_yml_parser.c			\
					$(PATH_PARSER_YML)save_yml_parser.c			\
					$(PATH_PARSER_YML)set_value.c				\
					$(PATH_PARSER_YML)yml_format.c				\
					$(PATH_PARSER_YML)display_yml_content.c

SRC_REGEX	=	

SRC_KAP += $(SRC_KSTR)
SRC_KAP += $(SRC_KUTILS)
SRC_KAP += $(SRC_MATHS)
SRC_KAP += $(SRC_KPRINTF)
SRC_KAP += $(SRC_HASHMAP)
SRC_KAP += $(SRC_LIST)
SRC_KAP +=	$(SRC_PARSER_JSON)
SRC_KAP += $(SRC_PARSER_XML)
SRC_KAP	+= $(SRC_REGEX)
SRC_KAP += $(SRC_KMEM)

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
	@rm -f $(OBJ_KAP)

.PHONY : all

clean:
	@find . \( -name "*.o" -or -name "*.a" \) -delete

.PHONY : clean

re:	clean all

.PHONY : re