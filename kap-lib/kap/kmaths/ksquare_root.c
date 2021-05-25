/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** ksquare_root
*/

#include <kap/kutils.h>

static bool check_square_root(kussize_t nb1, kussize_t nb2, kussize_t nb)
{
    if ((nb1 * nb2) == nb) {
        if (nb1 == nb2)
            return (true);
    }
    return (false);
}

kussize_t ksquare_root(kussize_t nb)
{
    kussize_t res = 0;

    if (nb <= 0)
        return (res);
    while (check_square_root(res, res, nb))
        res++;
    return (res);
}

kussize_t kroot(kusize_t nb UNUSED, kusize_t rt UNUSED)
{
    return (0);
}