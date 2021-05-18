/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kpower
*/

#include <kap/kutils.h>
#include <kap/kmath.h>

kdsize_t ksquare_root(kussize_t nb);

kdsize_t kpower(ksize_t num, ksize_t power)
{
    int r = 0;

    if (num == 0)
        return (0);
    if (power <= 0) {
        if (power == -2)
            return (ksquare_root(ABS(num)));
        if (power < 0)
            return (0);
        return (1);
    }
    r = num;
    for (ksize_t i = 1; i < power; i++)
        r = r * num;
    return (r);
}