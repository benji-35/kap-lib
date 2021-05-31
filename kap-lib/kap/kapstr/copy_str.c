/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** copy_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

string copy_str(cstring str)
{
    ksize_t size = length((string) str);
    string result = kmalloc(sizeof(char) * (size + 1));

    for (ksize_t i = 0; i < size; i++)
        result[i] = str[i];
    result[size] = 0;
    return (result);
}

string copy_str_fp(string str, ksize_t pos)
{
    ksize_t size = length(str);
    if (size <= pos)
        return (NULL);
    if (pos < 0)
        pos = 0;
    string cpy = kmalloc(sizeof(char) * ((size - pos) + 1));
    for (ksize_t i = pos; i < size; i++)
        cpy[i - pos] = str[i];
    cpy[size - pos] = 0;
    return (cpy);
}

string copy_str_tp(string str, ksize_t pos)
{
    if (pos <= 0)
        return (NULL);
    ksize_t size = length(str);
    if (pos >= size)
        pos = size - 1;
    string cpy = kmalloc(sizeof(char) * (pos + 1));
    for (ksize_t i = 0; i < pos; i++)
        cpy[i] = str[i];
    cpy[pos] = 0;
    return (cpy);
}

string copy_str_tc(string str, char c)
{
    if (str == NULL)
        return (NULL);
    string res = NULL;
    ksize_t pos_c = pos_char_str(str, c);

    if (pos_c == -1)
        return (NULL);
    res = kmalloc(sizeof(char) * (pos_c + 1));
    for (ksize_t i = 0; i < pos_c; i++)
        res[i] = str[i];
    res[pos_c] = 0;
    return (res);
}