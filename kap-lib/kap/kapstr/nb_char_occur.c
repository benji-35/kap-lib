/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** nb_char_occur
*/

#include <stdlib.h>
#include <kap/kstr.h>

ksize_t str_char_occur(string str, char c)
{
    ksize_t r = 0;

    if (str == NULL)
        return (r);
    for (ksize_t i = 0; str[i]; i++) {
        if (str[i] == c)
            r++;
    }
    return (r);
}