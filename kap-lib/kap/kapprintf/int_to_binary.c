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

static int get_begin(kssize_t nb, int minimize)
{
    kssize_t res = 0;
    while (kpower(2, res) < nb)
        res += 1;
    if (minimize)
        return (res);
    while (kdiv_by(res, 4) == 0)
        res++;
    return (res);
}

static void put_char_value_bin(kssize_t *nb, kssize_t puiss, char **str)
{
    kdsize_t p = kpower(2, puiss);
    if (*nb < p) {
        add_char_str(str, '0');
    } else {
        *nb = *nb - p;
        add_char_str(str, '1');
    }
}

char *int_to_binary(kssize_t nb, int flag, int minimize)
{
    char *str = empty_str();
    kssize_t puis = get_begin(nb, minimize);
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