/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-antman-benjamin.delvert
** File description:
** str_to_int
*/

#include <stdlib.h>
#include <kap/kutils.h>
#include <kap/kstr.h>

static bool my_is_number(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

int str_to_int(string str)
{
    if (str == NULL)
        return (0);
    int res = 0;
    ksize_t start = 0;
    if (str[0] == '-')
        start = 1;
    for (ksize_t i = start; my_is_number(str[i]); i++)
        res = (res * 10) + (str[i] - 48);
    if (start)
        res = res * -1;
    return (res);
}