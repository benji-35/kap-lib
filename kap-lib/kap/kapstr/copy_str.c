/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** copy_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

string copy_str(string str)
{
    int size = length(str);
    string result = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
        result[i] = str[i];
    result[size] = 0;
    return (result);
}

string copy_str_fp(string str, int pos)
{
    int size = length(str);
    if (size <= pos)
        return (NULL);
    if (pos < 0)
        pos = 0;
    string cpy = malloc(sizeof(char) * ((size - pos) + 1));
    for (int i = pos; i < size; i++)
        cpy[i - pos] = str[i];
    cpy[size - pos] = 0;
    return (cpy);
}

string copy_str_tp(string str, int pos)
{
    if (pos <= 0)
        return (NULL);
    int size = length(str);
    if (pos >= size)
        pos = size - 1;
    string cpy = malloc(sizeof(char) * (pos + 1));
    for (int i = 0; i < pos; i++)
        cpy[i] = str[i];
    cpy[pos] = 0;
    return (cpy);
}