/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** remove_first_char
*/

#include <stdlib.h>
#include <kap/kstr.h>

void str_rm_occhar(string *str, char c)
{
    int size = length(*str);
    string result;
    int nb_c = str_char_occur(*str, c);
    int curr = 0;
    if (nb_c == 0)
        return;
    result = malloc(sizeof(char) * (size - nb_c + 1));
    for (int i = 0; i < size; i++) {
        if ((*str)[i] != c) {
            result[i - curr] = (*str)[i];
        } else {
            curr++;
        }
    }
    result[size - nb_c] = 0;
    free(*str);
    *str = result;
}

void str_rm_fochar(string *str, char c)
{
    int size = length(*str);
    int nb_c = str_char_occur(*str, c);
    int curr = 0;

    if (nb_c == 0)
        return;
    string res = malloc(sizeof(char) * (size));
    for (int i = 0; i < size; i++) {
        if (curr == 0 && (*str)[i] == c) {
            curr ++;
        } else {
            res[i - curr] = (*str)[i];
        }
    }
    res[size - 1] = 0;
    free(*str);
    *str = res;
}

void str_rm_fchar(string *str)
{
    if (str == NULL || *str == NULL)
        return;
    int size = length(*str);
    string result = malloc(sizeof(char) * size);
    for (int i = 1; i < size; i++)
        result[i - 1] = (*str)[i];
    result[size - 1] = 0;
    free(*str);
    *str = result;
}

static void get_good_pos_rn(int *pos, int size)
{
    if (*pos < 0)
        *pos = 0;
    if (*pos > size)
        *pos = size;
}

void str_rm_pchar(string *str, int pos)
{
    if (str == NULL)
        return;
    int size = length(*str);
    int curr = 0;
    string res = malloc(sizeof(char) * size);

    get_good_pos_rn(&pos, size);
    for (int i = 0; i < pos; i++) {
        res[curr] = (*str)[i];
        curr++;
    }
    for (int i = pos + 1; i < size; i++) {
        res[curr] = (*str)[i];
        curr++;
    }
    res[size - 1] = 0;
    free(*str);
    *str = res;
}