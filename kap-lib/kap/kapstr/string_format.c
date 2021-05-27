/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** string_format
*/

#include <kap/kstr.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void str_format_flag(va_list *list, string *__cmd, ksize_t *index,\
    string *str);

string str_format(string __cmd, ...)
{
    string res = NULL;
    va_list list;
    va_start(list, __cmd);

    for (ksize_t i = 0; __cmd[i]; i++) {
        if (__cmd[i] == '%') {
            str_format_flag(&list, &__cmd, &i, &res);
        } else {
            add_char_strp(&res, __cmd[i], length(res));
        }
    }
    va_end(list);
    return (res);
}