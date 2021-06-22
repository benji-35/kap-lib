/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** int_to_hex
*/

#include <stdlib.h>
#include <kap/kstr.h>
#include <kap/kutils.h>
#include <kap/kmath.h>

char *int_to_binary(long long nb, int flag, int minimize);

static string tab_hex(void)
{
    string tab = concat_str("0123456789abcdef", NULL);
    return (tab);
}

static int size_hex(text splitted)
{
    int res = 0;
    for (int i = 0; splitted[i] != NULL; i++)
        res++;
    return (res);
}

static char val_hex(string str)
{
    int res = 0;
    string tab = tab_hex();
    char result = ' ';
    if (str[0] == '1')
        res += 8;
    if (str[1] == '1')
        res += 4;
    if (str[2] == '1')
        res += 2;
    if (str[3] == '1')
        res += 1;
    result = tab[res];
    kfree(tab);
    return (result);
}

string int_to_hexa(long long nb, int flag)
{
    string binary = int_to_binary(nb, 0, 0);
    text splitted = ksplit_interv(binary, 4);
    int size = size_hex(splitted);
    string hex = empty_str_size(size);
    for (int i = 0; i < size; i++)
        hex[i] = val_hex(splitted[i]);
    hex[size] = 0;
    free_text(splitted);
    kfree(binary);
    if (flag) {
        add_char_strp(&hex, 'x', 0);
        add_char_strp(&hex, '0', 0);
    }
    return (hex);
}