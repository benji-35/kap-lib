/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** advanced_split_str
*/

#include <stdlib.h>
#include <kap/kstr.h>
#include <stdarg.h>

void check_flag_avsplit(text *txt, va_list *list, char flg)
{
    text res = NULL;
    text res2 = NULL;

    if (flg != 's' && flg != 'c')
        return;
    if (flg == 's') {
        for (ksize_t i = 0; i < length_text(*txt); i++) {
            res2 = split_sstr((*txt)[i], va_arg(*list, string));
            add_text_text(&res, length_text(res), res2);
            free_text(res2);
        }
    } else {
        for (ksize_t i = 0; i < length_text(*txt); i++) {
            res2 = split_str((*txt)[i], va_arg(*list, int));
            add_text_text(&res, length_text(res), res2);
            free_text(res2);
        }
    }
    add_text_text(txt, length_text(*txt), res);
    free_text(res);
}

text advanced_split_str(string str, string __cmd, ...)
{
    text res = NULL;
    va_list list;
    ksize_t size = length(__cmd);

    add_str_text(&res, 0, str);
    va_start(list, __cmd);
    for (ksize_t i = 0; __cmd[i]; i++) {
        if (__cmd[i] == '%' && i < size - 1) {
            i++;
            check_flag_avsplit(&res, &list, __cmd[i]);
        }
    }
    return (res);
}