/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** display_base
*/

#include <stdlib.h>
#include <stdarg.h>
#include <kap/kstr.h>
#include <kap/kutils.h>
#include <kap/kmath.h>

char *int_to_binary(long long nb, int flag, int minimize);
string int_to_hexa(long long nb, int flag);

void display_binary(va_list *data, int nb, int fd)
{
    unsigned int nb_b = va_arg(*data, unsigned int);
    char *str = int_to_binary(nb_b, 1, 1);

    for (int i = 0; i < nb - length(str); i++)
        add_char_strp(&str, ' ', 0);
    my_putstr_fd(str, fd);
    kfree(str);
}

void display_hexa(va_list *data, int nb, int fd)
{
    unsigned int nb_b = va_arg(*data, unsigned int);
    char *str = int_to_hexa(nb_b, 0);

    for (int i = 0; i < nb - length(str); i++)
        add_char_strp(&str, ' ', 0);
    my_putstr_fd(str, fd);
    kfree(str);
}

void display_pointer(va_list *data, int nb, int fd)
{
    unsigned int nb_b = va_arg(*data, unsigned int);
    char *str = int_to_hexa(nb_b, 1);

    for (int i = 0; i < nb - length(str); i++)
        add_char_strp(&str, ' ', 0);
    my_putstr_fd(str, fd);
    kfree(str);
}

void display_char(va_list *data, int nb, int fd)
{
    char c = va_arg(*data, int);

    if (nb <= 1) {
        kput_char(c, fd);
        return;
    }
    for (int i = 0; i < nb - 1; i++)
        kput_char(' ', fd);
    kput_char(c, fd);
}

void display_str(va_list *data, int nb, int fd)
{
    string str = va_arg(*data, string);

    if (nb <= length(str)) {
        my_putstr_fd(str, fd);
        return;
    }
    for (int i = length(str); i < nb; i++)
        kput_char(' ', fd);
    my_putstr_fd(str, fd);
}