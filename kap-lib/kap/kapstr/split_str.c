/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** split_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

static int nb_split(string str, char splitter)
{
    int size = length(str);
    int result = 0;

    if (str[size - 1] == splitter)
        result--;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == splitter)
            result++;
    }
    return (result);
}

static int size_before_splitter(string str, char splitter)
{
    int i = 0;
    while (str[i] != 0) {
        if (str[i] == splitter)
            break;
        i++;
    }
    return (i);
}

static void complete_str_split(string str, int size, string result)
{
    for (int i = 0; i < size; i++)
        result[i] = str[i];
    result[size] = 0;
}

text split_str(string str, char spliter)
{
    int size = length(str);
    int nbsplit = nb_split(str, spliter);
    text result = malloc(sizeof(char *) * (nbsplit + 2));
    int curr = 0;
    for (int i = 0; i < size; i++) {
        int to_mal = size_before_splitter(str + i, spliter);
        result[curr] = malloc(sizeof(char) * (to_mal + 1));
        complete_str_split(str + i, to_mal, result[curr]);
        curr ++;
        i += to_mal;
    }
    result[nbsplit + 1] = NULL;
    return (result);
}