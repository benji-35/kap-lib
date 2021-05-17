/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** split_to_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

string text_to_str(text split, string separator)
{
    string str = NULL;
    string tampon = NULL;
    for (int i = 0; split[i] != NULL; i++) {
        tampon = concat_str(str, split[i]);
        free(str);
        if (split[i + 1] == NULL) {
            str = tampon;
        } else {
            str = concat_str(tampon, separator);
            free(tampon);
        }
    }
    return (str);
}