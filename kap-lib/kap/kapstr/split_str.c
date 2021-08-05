/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** split_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

static ksize_t nb_split(cstring str, char splitter)
{
    ksize_t size = length(str);
    ksize_t result = 0;

    if (str[size - 1] == splitter)
        result--;
    for (ksize_t i = 0; str[i] != 0; i++) {
        if (str[i] == splitter)
            result++;
    }
    return (result);
}

static ksize_t size_before_splitter(cstring str, char splitter)
{
    ksize_t i = 0;

    while (str[i] != 0) {
        if (str[i] == splitter)
            break;
        i++;
    }
    return (i);
}

static void complete_str_split(cstring str, ksize_t size, string result)
{
    for (ksize_t i = 0; i < size; i++)
        result[i] = str[i];
    result[size] = 0;
}

text split_str(cstring str, char spliter)
{
    ksize_t size = length(str);
    ksize_t nbsplit = nb_split(str, spliter);
    text result = kmalloc(sizeof(char *) * (nbsplit + 2));
    ksize_t to_mal;
    ksize_t curr = 0;

    for (ksize_t i = 0; i < size; i++) {
        to_mal = size_before_splitter(str + i, spliter);
        result[curr] = kmalloc(sizeof(char) * (to_mal + 1));
        complete_str_split(str + i, to_mal, result[curr]);
        curr ++;
        i += to_mal;
    }
    result[nbsplit + 1] = NULL;
    return (result);
}