/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-antman-benjamin.delvert
** File description:
** int_to_str
*/

#include <stdlib.h>
#include <kap/kstr.h>
#include <kap/kutils.h>

static int size_nb(int nb)
{
    int r = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        r++;
        nb = nb / 10;
    }
    return (r);
}

string int_to_str(int nb)
{
    int size = size_nb(nb);
    string result = malloc(sizeof(char) * (size + 1));

    if (nb == 0) {
        kfree(result);
        return (copy_str("0"));
    }
    for (int i = size - 1; i >= 0; i--) {
        result[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    result[size] = 0;
    return (result);
}