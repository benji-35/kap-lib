/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** int_to_binary
*/

#include <stdlib.h>
#include <kap/kstr.h>
#include <kap/kutils.h>
#include <kap/kmath.h>

static int get_begin(long long nb, int minimize)
{
    long long res = 0;
    while (kpower(2, res) < nb)
        res += 1;
    if (minimize)
        return (res);
    while (kdiv_by(res, 4) == 0)
        res++;
    return (res);
}

static void put_char_value_bin(long long *nb, int puiss, char **str)
{
    long long p = kpower(2, puiss);
    if (*nb < p) {
        add_char_str(str, '0');
    } else {
        *nb = *nb - p;
        add_char_str(str, '1');
    }
}

char *int_to_binary(long long nb, int flag, int minimize)
{
    char *str = empty_str();
    int puis = get_begin(nb, minimize);
    while (puis >= 0) {
        put_char_value_bin(&nb, puis, &str);
        puis--;
    }
    if (flag) {
        add_char_strp(&str, 'x', 0);
        add_char_strp(&str, '0', 0);
    }
    return (str);
}