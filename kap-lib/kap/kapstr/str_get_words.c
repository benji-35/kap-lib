/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** str_get_world
*/

#include <stdlib.h>
#include <kap/kstr.h>

int nb_o_split(text txt);

static int nb_split_w(string str)
{
    int size = length(str);
    int result = 0;

    if (is_alphanumeric(str[size - 1]) == 0)
        result--;
    for (int i = 0; str[i] != 0; i++) {
        if (is_alphanumeric(str[i]) == 0)
            result++;
    }
    return (result);
}

static int size_before_splitterw(string str)
{
    int i = 0;
    while (str[i] != 0) {
        if (is_alphanumeric(str[i]) == 0)
            break;
        i++;
    }
    return (i);
}

static void complete_str_splitw(string str, int size, string result)
{
    for (int i = 0; i < size; i++)
        result[i] = str[i];
    result[size] = 0;
}

static void rm_o_str(text *txt)
{
    int size = length_text(*txt);
    int nb_o = nb_o_split(*txt);
    int curr = 0;
    char **res = malloc(sizeof(char *) * ((size - nb_o) + 1));

    for (int i = 0; (*txt)[i] != NULL; i++) {
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
    int size = length(str);
    int nbsplit = nb_split_w(str);
    text result = malloc(sizeof(char *) * (nbsplit + 2));
    int curr = 0;

    for (int i = 0; i < size; i++) {
        int to_mal = size_before_splitterw(str + i);
        result[curr] = malloc(sizeof(char) * (to_mal + 1));
        complete_str_splitw(str + i, to_mal, result[curr]);
        curr ++;
        i += to_mal;
    }
    result[nbsplit + 1] = NULL;
    rm_o_str(&result);
    return (result);
}