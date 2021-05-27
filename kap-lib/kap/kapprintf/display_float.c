/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** display_float
*/

#include <stdarg.h>
#include <stdlib.h>
#include <kap/kstr.h>
#include <kap/kutils.h>

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
        add_char_strp(str, ((int)d % 10) + 48, 0);
        d = d / 10.0;
    }
    add_char_strp(str, '.', 0);
}

static void neg_double(int *neg, double *nb)
{
    if (*nb < 0.0) {
        *neg = 1;
        *nb = *nb * -1;
    }
}

static void rem_o_str(string *str)
{
    while ((*str)[0] == '0')
        str_rm_fchar(str);
}

void display_double(va_list *data, int bef, int fd)
{
    double f = va_arg(*data, double);
    int neg = 0;
    if (f == 0.0) {
        my_putstr_fd("0.0", fd);
        return;
    }
    char *str = empty_str();
    neg_double(&neg, &f);
    add_double_coma(f, &str);
    while (f > 0.0) {
        add_char_strp(&str, ((int)f % 10) + 48, 0);
        f = f / 10.0;
    }
    for (int i = 0; i < bef - length(str); i++)
        add_char_strp(&str, ' ', 0);
    if (neg)
        add_char_strp(&str, '-', 0);
    rem_o_str(&str);
    my_putstr_fd(str, fd);
    kfree(str);
}