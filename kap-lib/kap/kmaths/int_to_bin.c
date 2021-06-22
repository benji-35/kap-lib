/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** int_to_bin
*/

#include <kap/kutils.h>
#include <kap/kmath.h>
#include <kap/kstr.h>

static ksize_t bin_get_max(int nb) {
    ksize_t res = 0;

    while (kpower(2, res) < nb) {
        res++;
    }
    return res;
}

static string complete_bin(ksize_t max, int nb) {
    string res = NULL;
    ksize_t power_nb = 0;

    while (max >= 0) {
        power_nb = kpower(2, max);
        if (nb >= power_nb) {
            nb -= power_nb;
            add_char_str(&res, '1');
        } else if (res != NULL && nb < power_nb) {
            add_char_str(&res, '0');
        }
        max--;
    }
    return res;
}

string int_to_bin(int nb, bool flag) {
    string res = NULL;
    string tamp = NULL;
    ksize_t begin = bin_get_max(nb);

    if (nb < 0)
        return NULL;
    res = complete_bin(begin, nb);
    if (flag) {
        tamp = concat_str_pos(res, "0b", 0);
        kfree(res);
        res = tamp;
    }
    return res;
}