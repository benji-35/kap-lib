/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** check_flag
*/

#include <kap/kstr.h>
#include <stdlib.h>
#include <stdarg.h>

void check_flag(va_list list, string *__cmd, int *index)
{
    int nb = str_to_int((*__cmd) + (*index + 1));
    string str_nb = int_to_str(nb);
    int to_avance = *index + length(str_nb);
}