/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** concat_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

string concat_str(string str1, string str2)
{
    ksize_t s1 = length(str1);
    ksize_t s2 = length(str2);
    char *result = kmalloc(sizeof(char) * (s1 + s2 + 1));

    if ((str1 == NULL && str2 == NULL) || result == NULL) {
        kfree(result);
        return (NULL);
    }
    for (ksize_t i = 0; i < s1; i++)
        result[i] = str1[i];
    for (ksize_t i = s1; i < s1 + s2; i++)
        result[i] = str2[i - s1];
    result[s1 + s2] = 0;
    return (result);
}

static ksize_t check_pos_concat(string str1, ksize_t pos)
{
    int size;

    if (pos < 0)
        return 0;
    size = length(str1);
    if (pos > size)
        return size;
    return pos;
}

string concat_str_pos(string str1, string str2, ksize_t pos)
{
    ksize_t s1 = length(str1);
    ksize_t s2 = length(str2);
    char *result = kmalloc(sizeof(char) * (s1 + s2 + 1));
    pos = check_pos_concat(str1, pos);

    if ((str1 == NULL && str2 == NULL) || result == NULL) {
        kfree(result);
        return NULL;
    }
    for (ksize_t i = 0; i < pos; i++)
        result[i] = str1[i];
    for (ksize_t i = pos + s2; i < s1 + s2; i++)
        result[i] = str1[i - s2];
    for (ksize_t i = pos; i < pos + s2; i++)
        result[i] = str2[i - pos];
    result[s1 + s2] = 0;
    return (result);
}

void concat_str_nm(string *str1, string str2)
{
    string tampon = concat_str(*str1, str2);

    kfree(*str1);
    *str1 = tampon;
}

void concat_str_pos_nm(string *str1, string str2, ksize_t pos)
{
    string tampon = concat_str_pos(*str1, str2, pos);

    kfree(*str1);
    *str1 = tampon;
}