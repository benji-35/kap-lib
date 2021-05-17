/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** display_base
*/

#include <stdlib.h>
#include <stdarg.h>
#include <kap/kstr.h>

char *int_to_binary(unsigned int nb, int flag, int minimize);
char *int_to_hex(unsigned int nb, int flag);
void add_char_str_before(char **str, char c);

void display_binary(va_list *data, int nb)
{
    unsigned int nb_b = va_arg(*data, unsigned int);
    char *str = int_to_binary(nb_b, 1, 1);
    for (int i = 0; i < nb - length(str); i++)
        add_char_str_before(&str, ' ');
    my_putstr(str);
    free(str);
}

void display_hexa(va_list *data, int nb)
{
    unsigned int nb_b = va_arg(*data, unsigned int);
    char *str = int_to_hex(nb_b, 0);
    for (int i = 0; i < nb - length(str); i++)
        add_char_str_before(&str, ' ');
    my_putstr(str);
    free(str);
}

void display_pointer(va_list *data, int nb)
{
    unsigned int nb_b = va_arg(*data, unsigned int);
    char *str = int_to_hex(nb_b, 1);
    for (int i = 0; i < nb - length(str); i++)
        add_char_str_before(&str, ' ');
    my_putstr(str);
    free(str);
}

void display_char(va_list *data, int nb)
{
    char c = va_arg(*data, int);
    if (nb <= 1) {
        my_putchar(c);
        return;
    }
    for (int i = 0; i < nb - 1; i++)
        my_putchar(' ');
    my_putchar(c);
}