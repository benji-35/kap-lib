/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** check_flag
*/

#include <kaprintf/kaprintf_n.h>
#include <kap/kstr.h>
#include <stdlib.h>
#include <stdarg.h>

void kprintf(string __cmd, ...);

void check_flag(va_list *list, string *__cmd, int *index)
{
    int nb = str_to_int((*__cmd) + (*index + 1));
    string str_nb = int_to_str(nb);
    int to_avance = *index + length(str_nb) + 1;

    for (int i = 0; i < FLAG_LENGTH; i++) {
        if (strat_with((*__cmd) + to_avance, pflags[i].flag)) {
            pflags[i].display(list, nb);
            *index = to_avance + length(pflags[i].flag) - 1;
            return;
        }
    }
    kput_char('%');
}