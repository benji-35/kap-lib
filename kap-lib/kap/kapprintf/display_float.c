/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** display_float
*/

#include <stdarg.h>
#include <stdlib.h>

int lenght(char *str);
void putstr(char *str);
void add_char_in_str(char **str, char c);
char *empty_str(void);
void add_char_str_before(char **str, char c);
char *mall_str(char *str);
void delete_o(char **str);

static void add_double_coma(double d, char **str)
{
    for (int i = 0; i < 7; i++)
        d = d * 10.0;
    int b = (int)d % 10;
    int a = (int)(d / 10.0) % 10;
    if (b >= a && b != 0) {
        d = d /10.0;
        d++;
        d = d * 10.0;
    }
    for (int i = 0; i < 7; i++) {
        add_char_str_before(str, ((int)d % 10) + 48);
        d = d / 10.0;
    }
    add_char_str_before(str, '.');
}

static void neg_double(int *neg, double *nb)
{
    if (*nb < 0.0) {
        *neg = 1;
        *nb = *nb * -1;
    }
}

void display_double(va_list *data, int bef)
{
    double f = va_arg(*data, double);
    int neg = 0;
    if (f == 0.0) {
        putstr("0.0");
        return;
    }
    char *str = empty_str();
    neg_double(&neg, &f);
    add_double_coma(f, &str);
    while (f > 0.0) {
        add_char_str_before(&str, ((int)f % 10) + 48);
        f = f / 10.0;
    }
    for (int i = 0; i < bef - lenght(str); i++)
        add_char_str_before(&str, ' ');
    if (neg)
        add_char_str_before(&str, '-');
    delete_o(&str);
    putstr(str);
    free(str);
}