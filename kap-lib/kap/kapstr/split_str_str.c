/*
** EPITECH PROJECT, 2021
** C-Strlib
** File description:
** split_str_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

static ksize_t nb_ssplit(string str, string splitter)
{
    ksize_t size = length(str);
    ksize_t size_s = length(splitter);
    ksize_t result = 0;

    if (str_equality(str + size - 1 - size_s, splitter))
        result--;
    for (ksize_t i = 0; str[i] != 0; i++) {
        if (strat_with(str + i, splitter))
            result++;
    }
    return (result);
}

static int ssize_before_splitter(string str, string splitter)
{
    ksize_t i = 0;
    ksize_t size = length(str);

    while (str[i] != 0) {
        if (strat_with(str + i, splitter))
            break;
        i++;
    }
    if (i > size)
        i = size;
    return (i);
}

static void complete_sstr_split(string str, string split, string *res,\
    ksize_t *i)
{
    ksize_t size_s = length(split);
    ksize_t size = ssize_before_splitter(str, split);

    *res = kmalloc(sizeof(char) * (size + 1));
    if (*res == NULL)
        return;
    for (ksize_t i = 0; i < size; i++)
        (*res)[i] = str[i];
    (*res)[size] = 0;
    *i = *i + size + size_s - 1;
}

text split_sstr(string str, string splitter)
{
    ksize_t curr = 0;
    ksize_t size = length(str);
    ksize_t nb_split = nb_ssplit(str, splitter);
    text split = kmalloc(sizeof(string) * (nb_split + 2));

    for (ksize_t i = 0; i < size; i++) {
        complete_sstr_split(str + i, splitter, &split[curr], &i);
        curr++;
    }
    split[nb_split + 1] = NULL;
    return (split);
}