/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** check_flag
*/

#include <kapformats/kaprintf_n.h>
#include <kap/kstr.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void check_flag(va_list *list, string *__cmd, int *index, int fd)
{
    int nb = str_to_int((*__cmd) + (*index + 1));
    string str_nb = int_to_str(nb);
    int to_add = length(str_nb);
    int to_avance = *index + 1;

    if (str_nb != NULL)
        kfree(str_nb);
    if (nb > 0)
        to_avance += to_add;
    for (int i = 0; i < FLAG_LENGTH; i++) {
        if (strat_with((*__cmd) + to_avance, pflags[i].flag)) {
            pflags[i].display(list, nb, fd);
            *index = to_avance + length(pflags[i].flag) - 1;
            return;
        }
    }
    kput_char('%', fd);
}