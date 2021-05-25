/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kaprintf
*/

#include <kap/kutils.h>
#include <kapformats/kaprintf_n.h>
#include <stdarg.h>

void check_flag(va_list *list, string *__cmd, int *index, int fd);

void kprintf(string __cmd, ...)
{
    va_list list;
    va_start(list, __cmd);
    for (int i = 0; __cmd[i]; i++) {
        if (__cmd[i] == '%') {
            check_flag(&list, &__cmd, &i, kstdout);
        } else {
            kput_char(__cmd[i], kstdout);
        }
    }
    va_end(list);
}

void kfprintf(int fd, string __cmd, ...)
{
    va_list list;
    va_start(list, __cmd);
    for (int i = 0; __cmd[i]; i++) {
        if (__cmd[i] == '%') {
            check_flag(&list, &__cmd, &i, fd);
        } else {
            kput_char(__cmd[i], fd);
        }
    }
    va_end(list);
}