/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** display_long
*/

#include <stdarg.h>
#include <stdlib.h>
#include <kap/kstr.h>
#include <kap/kutils.h>

void display_long(va_list *data, int bef, int fd)
{
    long nb = va_arg(*data, long);
    if (nb == 0) {
        my_putstr_fd("0", fd);
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_str(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - length(str); i++)
        add_char_strp(&str, ' ', 0);
    my_putstr_fd(str, fd);
    kfree(str);
}

void display_ulong(va_list *data, int bef, int fd)
{
    unsigned long nb = va_arg(*data, unsigned long);
    if (nb == 0) {
        my_putstr_fd("0", fd);
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_str(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - length(str); i++)
        add_char_strp(&str, ' ', 0);
    my_putstr_fd(str, fd);
    kfree(str);
}

void display_longlong(va_list *data, int bef, int fd)
{
    long long nb = va_arg(*data, long long);
    if (nb == 0) {
        my_putstr_fd("0", fd);
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_str(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - length(str); i++)
        add_char_strp(&str, ' ', 0);
    my_putstr_fd(str, fd);
    kfree(str);
}

void display_ulonglong(va_list *data, int bef, int fd)
{
    unsigned long long nb = va_arg(*data, unsigned long long);
    if (nb == 0) {
        my_putstr_fd("0", fd);
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_str(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - length(str); i++)
        add_char_strp(&str, ' ', 0);
    my_putstr_fd(str, fd);
    kfree(str);
}