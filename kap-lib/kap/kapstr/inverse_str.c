/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** inverse_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

void reverse_str(string *str)
{
    if (str == NULL)
        return;
    ksize_t size = length(*str);
    char tampon = 0;
    for (ksize_t i = 0; i < size / 2; i++) {
        tampon = (*str)[i];
        (*str)[i] = (*str)[(size - 1) - i];
        (*str)[(size - 1) - i] = tampon;
    }
}