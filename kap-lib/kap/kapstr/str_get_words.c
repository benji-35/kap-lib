/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** str_get_world
*/

#include <stdlib.h>
#include <kap/kstr.h>

static ksize_t nb_split_w(string str)
{
    ksize_t size = length(str);
    ksize_t result = 0;

    if (is_alphanumeric(str[size - 1]) == 0)
        result--;
    for (ksize_t i = 0; str[i] != 0; i++) {
        if (is_alphanumeric(str[i]) == 0)
            result++;
    }
    return (result);
}

static ksize_t size_before_splitterw(string str)
{
    ksize_t i = 0;
    while (str[i] != 0) {
        if (is_alphanumeric(str[i]) == 0)
            break;
        i++;
    }
    return (i);
}

static void complete_str_splitw(string str, ksize_t size, string result)
{
    for (ksize_t i = 0; i < size; i++)
        result[i] = str[i];
    result[size] = 0;
}

static void rm_o_str(text *txt)
{
    ksize_t size = length_text(*txt);
    ksize_t nb_o = nb_o_split(*txt);
    ksize_t curr = 0;
    char **res = kmalloc(sizeof(char *) * ((size - nb_o) + 1));

    for (ksize_t i = 0; (*txt)[i] != NULL; i++) {
        if (str_equality((*txt)[i], "\0")) {
            curr++;
        } else {
            res[i - curr] = copy_str((*txt)[i]);
        }
    }
    res[size - nb_o] = NULL;
    free_text(*txt);
    *txt = res;
}

text get_words(string str)
{
    if (str == NULL)
        return NULL;
    ksize_t size = length(str);
    ksize_t nbsplit = nb_split_w(str);
    text result = kmalloc(sizeof(char *) * (nbsplit + 2));
    ksize_t curr = 0;
    ksize_t to_mal;

    for (ksize_t i = 0; i < size; i++) {
        to_mal = size_before_splitterw(str + i);
        result[curr] = kmalloc(sizeof(char) * (to_mal + 1));
        complete_str_splitw(str + i, to_mal, result[curr]);
        curr ++;
        i += to_mal;
    }
    result[nbsplit + 1] = NULL;
    rm_o_str(&result);
    return (result);
}