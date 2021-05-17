/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** start_with
*/

#include <kap/kstr.h>

int strat_with(string str1, string str2)
{
    int s1 = length(str1);
    int s2 = length(str2);
    if (s2 > s1)
        return (0);
    for (int i = 0; i < s2; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}