/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** start_with
*/

#include <kap/kstr.h>

bool strat_with(string str1, string str2)
{
    ksize_t s1 = length(str1);
    ksize_t s2 = length(str2);
    if (s2 > s1)
        return (false);
    for (ksize_t i = 0; i < s2; i++) {
        if (str1[i] != str2[i])
            return (false);
    }
    return (true);
}