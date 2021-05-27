/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** add_istr
*/

#include <stdlib.h>
#include <kap/kstr.h>
#include <kapformats/kap_str_n.h>

void add_intstr(string *str, va_list *list, int spaces)
{
    int i = va_arg(*list, int);
    string int_str = int_to_str(i);
    string tampon = NULL;

    for (ksize_t i = length(int_str); i < spaces; i++)
        add_char_strp(&int_str, ' ', 0);
    tampon = concat_str(*str, int_str);
    kfree(*str);
    kfree(int_str);
    *str = tampon;
}

void add_doublestr(string *str, va_list *list, int spaces)
{
    double i = va_arg(*list, double);
    string int_str = double_to_str(i, 15);
    string tampon = NULL;

    for (ksize_t i = length(int_str); i < spaces; i++)
        add_char_strp(&int_str, ' ', 0);
    tampon = concat_str(*str, int_str);
    kfree(*str);
    kfree(int_str);
    *str = tampon;
}

void add_charstr(string *str, va_list *list, int spaces)
{
    char c = va_arg(*list, int);
    
    add_char_strp(str, c, length(*str));

    for (ksize_t i = length(*str); i < spaces; i++)
        add_char_strp(str, ' ', length(*str) - 1);
}

void add_strstr(string *str, va_list *list, int spaces)
{
    string s = va_arg(*list, string);
    string tampon = NULL;

    for (ksize_t i = length(s); i < spaces; i++)
        add_char_strp(&s, ' ', 0);
    tampon = concat_str(*str, s);
    kfree(*str);
    *str = tampon;
}

void add_binstr(string *str, va_list *list, int spaces)
{
    kssize_t nb = va_arg(*list, kssize_t);
    string bin = int_to_binary(nb, 0, 1);
    string tampon = NULL;

    for (ksize_t i = length(bin); i < spaces; i++)
        add_char_strp(&bin, ' ', 0);
    tampon = concat_str(*str, bin);
    kfree(*str);
    *str = tampon;
}

void add_binfstr(string *str, va_list *list, int spaces)
{
    kssize_t nb = va_arg(*list, kssize_t);
    string bin = int_to_binary(nb, 1, 1);
    string tampon = NULL;

    for (ksize_t i = length(bin); i < spaces; i++)
        add_char_strp(&bin, ' ', 0);
    tampon = concat_str(*str, bin);
    kfree(*str);
    *str = tampon;
}

void add_hexstr(string *str, va_list *list, int spaces)
{
    kssize_t nb = va_arg(*list, kssize_t);
    string bin = int_to_hex(nb, 0);
    string tampon = NULL;

    for (ksize_t i = length(bin); i < spaces; i++)
        add_char_strp(&bin, ' ', 0);
    tampon = concat_str(*str, bin);
    kfree(*str);
    *str = tampon;
}

void add_hexfstr(string *str, va_list *list, int spaces)
{
    kssize_t nb = va_arg(*list, kssize_t);
    string bin = int_to_hex(nb, 1);
    string tampon = NULL;

    for (ksize_t i = length(bin); i < spaces; i++)
        add_char_strp(&bin, ' ', 0);
    tampon = concat_str(*str, bin);
    kfree(*str);
    *str = tampon;
}
