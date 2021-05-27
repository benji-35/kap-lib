/*
** EPITECH PROJECT, 2021
** C-Strlib
** File description:
** remove_str_text
*/

#include <stdlib.h>
#include <kap/kstr.h>


void remove_ostr_str(string *str, string to_rem)
{
    ksize_t size = length(to_rem);
    ksize_t index = str_contain_pos(*str, to_rem);

    while (index != -1) {
        for (int i = 0; i < size; i++)
            str_rm_pchar(str, index);
        index = str_contain_pos(*str, to_rem);
    }
}

void remove_all_ostr_text(text text, string str)
{
    for (ksize_t i = 0; text[i] != NULL; i++) {
        if (str_contains(text[i], str))
            remove_ostr_str(&text[i], str);
    }
}