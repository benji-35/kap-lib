/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** is_prime
*/

#include <kap/kutils.h>
#include <kap/kmath.h>

static bool is_first_prime(ksize_t nb)
{
    if (nb == 2)
        return (true);
    if (nb == 3)
        return (true);
    if (nb == 5)
        return (true);
    if (nb == 7)
        return (true);
    return (false);
}

bool is_prime(ksize_t nb)
{
    if (nb < 0)
        return false;
    if (is_first_prime(nb))
        return true;
    for (short i = 1; i < 10; i++) {
        if (kdiv_by(nb, i))
            return false;
    }
    return true;
}

ksize_t get_prime_sup(ksize_t nb)
{
    if (nb < 0)
        return 0;
    while (!is_prime(nb))
        nb++;
    return nb;
}

ksize_t get_prime_min(ksize_t nb)
{
    if (nb < 0)
        return 0;
    while (!is_prime(nb))
        nb--;
    return nb;
}