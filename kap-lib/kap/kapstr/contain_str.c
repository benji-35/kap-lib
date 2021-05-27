/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** contain_str
*/

#include <kap/kstr.h>

bool str_contains(string str1, string contain)
{
    int s1 = length(str1);
    int curr = 0;

    if (length(contain) > s1 || length(contain) == 0)
        return (false);
    for (int i = 0; i < s1; i++) {
        if (curr > 0 && str1[i] != contain[curr])
            curr = 0;
        if (str1[i] == contain[curr])
            curr++;
        if (curr == length(contain))
            return (true);
    }
    return (false);
}

int str_contain_pos(string str1, string contain)
{
    int s1 = length(str1);
    int curr = 0;

    if (length(contain) > s1 || length(contain) == 0)
        return (-1);
    for (int i = 0; i < s1; i++) {
        if (curr > 0 && str1[i] != contain[curr])
            curr = 0;
        if (str1[i] == contain[curr])
            curr++;
        if (curr == length(contain))
            return (i - length(contain) + 1);
    }
    if (curr == length(contain))
        return (s1 - length(contain) + 1);
    return (-1);
}