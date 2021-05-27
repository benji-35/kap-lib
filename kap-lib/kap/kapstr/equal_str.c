/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** equal_str
*/

#include <kap/kstr.h>

bool str_equality(string str1, string str2)
{
    ksize_t s1 = length(str1);

    if (s1 != length(str2))
        return (0);
    for (int i = 0; i < s1; i++) {
        if (str1[i] != str2[i])
            return (false);
    }
    return (true);
}

bool str_equality_tp(string str1, string str2, ksize_t pos)
{
    ksize_t s1 = length(str1);

    if (s1 < pos)
        pos = s1;
    for (int i = 0; i < pos; i++) {
        if (str1[i] != str2[i])
            return (false);
    }
    return (true);
}

bool contain_only_char_tp(string str1, char c, ksize_t pos)
{
    int s = length(str1);

    if (s < pos)
        pos = s;
    for (int i = 0; i < pos; i++) {
        if (str1[i] != c)
            return (false);
    }
    return (true);
}