/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** nb_chars
*/

#include <kap/kstr.h>

ksize_t nb_fchars(cstring str, char c)
{
    ksize_t res = 0;

    for (ksize_t i = 0; i < length(str); i++) {
        if (str[i] != c)
            break;
        res++;
    }
    return res;
}