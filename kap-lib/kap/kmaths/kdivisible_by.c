/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kdivisible_by
*/

#include <kap/kutils.h>

bool kdiv_by(kssize_t num, kssize_t div)
{
    kdsize_t f = (kdsize_t)num / (kdsize_t)div;
    ksize_t i = num / div;
    if ((kdsize_t)i == f)
        return (true);
    return (false);
}