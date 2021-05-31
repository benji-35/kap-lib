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
    string str = kmalloc(sizeof(char) * 1);
    str[0] = 0;
    return (str);
}

string empty_str_size(ksize_t size)
{
    if (size < 0)
        return (NULL);
    string str = kmalloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
        str[i] = ' ';
    str[size] = 0;
    return (str);
}