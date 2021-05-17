/*
** EPITECH PROJECT, 2021
** C-Strlib
** File description:
** char_is_an
*/

#include <stdlib.h>
#include <kap/kstr.h>

int is_alphanumeric(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int nb_o_split(text str)
{
    int r = 0;
    for (int i = 0; str[i] != NULL; i++) {
        if (str_equality(str[i], "\0"))
            r++;
    }
    return (r);
}