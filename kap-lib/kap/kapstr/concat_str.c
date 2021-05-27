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
    ksize_t s1 = length(str1);
    ksize_t s2 = length(str2);
    char *result = malloc(sizeof(char) * (s1 + s2 + 1));

    if ((str1 == NULL && str2 == NULL) || result == NULL) {
        kfree(result);
        return (NULL);
    }
    for (ksize_t i = 0; i < s1; i++)
        result[i] = str1[i];
    for (ksize_t i = s1; i < s1 + s2; i++)
        result[i] = str2[i - s1];
    result[s1 + s2] = 0;
    return (result);
}