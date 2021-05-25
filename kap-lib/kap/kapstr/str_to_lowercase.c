/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** str_to_lowercase
*/

#include <kap/kstr.h>

void str_to_lower_case(string str)
{
    if (str == KNULL)
        return;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

void str_to_upper_case(string str)
{
    if (str == KNULL)
        return;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}