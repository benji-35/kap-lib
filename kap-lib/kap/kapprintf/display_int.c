/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** display_int
*/

#include <stdarg.h>
#include <stdlib.h>
#include <kap/kstr.h>
#include <kap/kutils.h>

void display_int(va_list *data, int bef, int fd)
{
    int nb = va_arg(*data, int);
    int neg = 0;
    if (nb == 0) {
        my_putstr_fd("0", fd);
        return;
    }
    if (nb < 0) {
        neg = 1;
        nb = nb * -1;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_strp(&str, (nb % 10) + 48, 0);
        nb = nb / 10;
    }
    if (neg)
        add_char_strp(&str, '-', 0);
    for (int i = 0; i < bef - length(str); i++)
        add_char_strp(&str, ' ', 0);
    my_putstr_fd(str, fd);
    kfree(str);
}

void display_unisgned_int(va_list *data, int bef, int fd)
{
    unsigned int nb = va_arg(*data, unsigned int);
    if (nb == 0) {
        my_putstr_fd("0", fd);
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_strp(&str, (nb % 10) + 48, 0);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - length(str); i++)
        add_char_strp(&str, ' ', 0);
    my_putstr_fd(str, fd);
    kfree(str);
}

void display_short(va_list *data, int bef, int fd)
{
    display_int(data, bef, fd);
}

void display_unsigned_short(va_list *data, int bef, int fd)
{
    display_int(data, bef, fd);
}