/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** empty_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

string empty_str(void)
{
    string str = malloc(sizeof(char) * 1);
    str[0] = 0;
    return (str);
}

string empty_str_size(int size)
{
    if (size < 0)
        return (NULL);
    string str = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
        str[i] = ' ';
    str[size] = 0;
    return (str);
}