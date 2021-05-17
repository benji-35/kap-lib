/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** finish_with
*/

#include <kap/kstr.h>

int finish_with(string str1, string str2)
{
    int s1 = length(str1);
    int s2 = length(str2);

    if (s2 > s1)
        return (0);
    for (int i = 0; i < s2; i++) {
        if (str1[s1 - 1 - i] != str2[s2 - 1 - i])
            return (0);
    }
    return (1);
}