/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kdivisible_by
*/

#include <kap/kutils.h>

bool_t kdiv_by(kssize_t num, kssize_t div)
{
    double f = (double)num / (double)div;
    int i = num / div;
    if ((double)i == f)
        return (true);
    return (false);
}