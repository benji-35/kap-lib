/*
** EPITECH PROJECT, 2021
** C-Strlib
** File description:
** float_to_car
*/

#include <stdlib.h>
#include <kap/kstr.h>

static int nb_o(string str, ksize_t size)
{
    ksize_t res = 0;
    for (ksize_t i = 0; i < size; i++) {
        if (str[i] != '0')
            break;
        res++;
    }
    return (res);
}

static void delete_o(string *str)
{
    int size = length(*str);
    int nb = nb_o(*str, size);
    if (nb == 0)
        return;
    char *new_str = kmalloc(sizeof(char) * (size - nb));
    for (int i = nb; i < size; i++)
        new_str[i - nb] = (*str)[i];
    kfree(*str);
    new_str[size - nb - 1] = 0;
    *str = new_str;
}

static void add_double_coma(double d, string *str, int precision)
{
    for (int i = 0; i < precision; i++)
        d = d * 10.0;
    int b = (int)d % 10;
    int a = (int)(d / 10.0) % 10;
    if (b >= a && b != 0) {
        d = d /10.0;
        d++;
        d = d * 10.0;
    }
    for (int i = 0; i < precision; i++) {
        insert_char_str(str, 0, ((int)d % 10) + 48);
        d = d / 10.0;
    }
    insert_char_str(str, 0, '.');
}

static void neg_double(int *neg, double *nb)
{
    if (*nb < 0.0) {
        *neg = 1;
        *nb = *nb * -1;
    }
}

string double_to_str(double f, int precision)
{
    int neg = 0;
    precision++;
    if (f == 0.0)
        return (copy_str("0.0"));
    char *str = empty_str();
    neg_double(&neg, &f);
    add_double_coma(f, &str, precision);
    while (f > 0.0) {
        insert_char_str(&str, 0, ((int)f % 10) + 48);
        f = f / 10.0;
    }
    if (neg)
        insert_char_str(&str, 0, '-');
    delete_o(&str);
    if (str[length(str) - 1] == '.')
        str[length(str) - 1] = 0;
    return (str);
}