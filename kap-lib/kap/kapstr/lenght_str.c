/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** length_str
*/

#include <stdlib.h>
#include <kap/kutils.h>
#include <kap/kstr.h>

ksize_t length(cstring str)
{
    ksize_t r = 0;

    if (str == NULL)
        return (r);
    while (str[r] != 0)
        r++;
    return (r);
}

ksize_t length_text(text split)
{
    ksize_t r = 0;

    if (split == NULL)
        return (r);
    while (split[r] != NULL)
        r++;
    return (r);
}

bool str_isempty(cstring str)
{
    if (str == NULL)
        return true;
    if (length(str) == 0)
        return true;
    return false;
}