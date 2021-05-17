/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** concat_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

string concat_str(string str1, string str2)
{
    int s1 = length(str1);
    int s2 = length(str2);
    char *result = malloc(sizeof(char) * (s1 + s2 + 1));

    for (int i = 0; i < s1; i++)
        result[i] = str1[i];
    for (int i = s1; i < s1 + s2; i++)
        result[i] = str2[i - s1];
    result[s1 + s2] = 0;
    return (result);
}