/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** display_long
*/

#include <stdarg.h>
#include <stdlib.h>

int lenght(char *str);
void putstr(char *str);
void add_char_in_str(char **str, char c);
char *empty_str(void);
void add_char_str_before(char **str, char c);
char *mall_str(char *str);

void display_long(va_list *data, int bef)
{
    long nb = va_arg(*data, long);
    if (nb == 0) {
        putstr("0");
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_in_str(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - lenght(str); i++)
        add_char_str_before(&str, ' ');
    putstr(str);
    free(str);
}

void display_ulong(va_list *data, int bef)
{
    unsigned long nb = va_arg(*data, unsigned long);
    if (nb == 0) {
        putstr("0");
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_in_str(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - lenght(str); i++)
        add_char_str_before(&str, ' ');
    putstr(str);
    free(str);
}

void display_longlong(va_list *data, int bef)
{
    long long nb = va_arg(*data, long long);
    if (nb == 0) {
        putstr("0");
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_in_str(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - lenght(str); i++)
        add_char_str_before(&str, ' ');
    putstr(str);
    free(str);
}

void display_ulonglong(va_list *data, int bef)
{
    unsigned long long nb = va_arg(*data, unsigned long long);
    if (nb == 0) {
        putstr("0");
        return;
    }
    char *str = empty_str();
    while (nb != 0) {
        add_char_in_str(&str, (nb % 10) + 48);
        nb = nb / 10;
    }
    for (int i = 0; i < bef - lenght(str); i++)
        add_char_str_before(&str, ' ');
    putstr(str);
    free(str);
}