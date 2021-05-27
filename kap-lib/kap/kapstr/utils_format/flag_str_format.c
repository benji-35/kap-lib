/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** flag_str_format
*/

#include <kap/kstr.h>
#include <kapformats/kap_str_n.h>
#include <stdlib.h>

void str_format_flag(va_list *list, string *__cmd, ksize_t *index,\
    string *str)
{
    int nb = str_to_int((*__cmd) + (*index + 1));
    string str_nb = int_to_str(nb);
    ksize_t to_add = length(str_nb);
    ksize_t to_avance = *index + 1;

    if (str_nb != NULL)
        kfree(str_nb);
    if (nb > 0)
        to_avance += to_add;
    for (ksize_t i = 0; i < SFLAG_LENGTH; i++) {
        if (strat_with((*__cmd) + to_avance, strflags[i].flag)) {
            strflags[i].display(str, list, nb);
            *index = to_avance + length(strflags[i].flag) - 1;
            return;
        }
    }
    add_char_strp(str, '%', length(*str));
}