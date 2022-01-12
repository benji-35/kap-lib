/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** ksquare_root
*/

#include <kap/kutils.h>
#include <kap/kmath.h>

static void check_square_root(kdsize_t *b1, kdsize_t *b2, double precision,
    kdsize_t nb)
{
    while (SQUARE(*b2) < nb) {
        *b1 = *b2;
        *b2 += precision;
        if (SQUARE(*b2) == nb)
            return;
    }
}

kdsize_t ksquare_root(kdsize_t nb)
{
    kdsize_t b1 = 0;
    kdsize_t b2 = 1;
    double precision = 1;

    while (SQUARE(b1) != nb || SQUARE(b2) != nb) {
        check_square_root(&b1, &b2, precision, nb);
        if (SQUARE(b1) == nb)
            return b1;
        if (SQUARE(b2) == nb)
            return b2;
        precision = precision / 10;
        if (precision < 0.0000000001)
            return b2;
        b2 = b1;
        b1 -= precision;
    }
    return b2;
}
