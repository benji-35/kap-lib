/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** display_int
*/

#include <stdarg.h>
#include <stdlib.h>

int lenght(char *str);
void putstr(char *str);
void add_char_in_str(char **str, char c);
char *empty_str(void);
void add_char_str_before(char **str, char c);
char *mall_str(char *str);
void inverse_str(char **str);

void display_int(va_list *data, int bef)
{
    int nb = va_arg(*data, int);
    int neg = 0;
    if (nb == 0) {
        putstr("0");
        return;
    }
    if (nb < 0) {
        neg = 1;
        nb = nb * -1;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_str_before(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    if (neg)
        add_char_str_before(&str, '-');
    for (int i = 0; i < bef - lenght(str); i++)
        add_char_str_before(&str, ' ');
    putstr(str);
    free(str);
}

void display_unisgned_int(va_list *data, int bef)
{
    unsigned int nb = va_arg(*data, unsigned int);
    if (nb == 0) {
        putstr("0");
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_str_before(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - lenght(str); i++)
        add_char_str_before(&str, ' ');
    putstr(str);
    free(str);
}

void display_short(va_list *data, int bef)
{
    display_int(data, bef);
}

void display_unsigned_short(va_list *data, int bef)
{
    display_int(data, bef);
}