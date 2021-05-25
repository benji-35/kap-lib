/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** equal_str
*/

#include <kap/kstr.h>

int str_equality(string str1, string str2)
{
    int s1 = length(str1);

    if (s1 != length(str2))
        return (0);
    for (int i = 0; i < s1; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}

int str_equality_tp(string str1, string str2, int nb)
{
    int s1 = length(str1);

    if (s1 < nb)
        nb = s1;
    for (int i = 0; i < nb; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}

int contain_only_char_tp(string str1, char c, int pos)
{
    int s = length(str1);

    if (s < pos)
        pos = s;
    for (int i = 0; i < pos; i++) {
        if (str1[i] != c)
            return (0);
    }
    return (1);
}