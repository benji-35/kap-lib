/*
** EPITECH PROJECT, 2021
** C-Strlib
** File description:
** char_is_an
*/

#include <stdlib.h>
#include <kap/kstr.h>

bool is_alphanumeric(char c)
{
    if (c >= 'a' && c <= 'z')
        return (true);
    if (c >= 'A' && c <= 'Z')
        return (true);
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

ksize_t nb_o_split(text str)
{
    ksize_t r = 0;
    for (ksize_t i = 0; str[i] != NULL; i++) {
        if (str_equality(str[i], "\0"))
            r++;
    }
    return (r);
}