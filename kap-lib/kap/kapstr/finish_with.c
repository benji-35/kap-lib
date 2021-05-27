/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** finish_with
*/

#include <kap/kstr.h>

bool finish_with(string str1, string str2)
{
    ksize_t s1 = length(str1);
    ksize_t s2 = length(str2);

    if (s2 > s1)
        return (0);
    for (ksize_t i = 0; i < s2; i++) {
        if (str1[s1 - 1 - i] != str2[s2 - 1 - i])
            return (0);
    }
    return (1);
}