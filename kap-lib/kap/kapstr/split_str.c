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

    if (size <= 0)
        return 0;
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
    if (size == 0) {
        result[nbsplit] = NULL;
    }
    result[nbsplit + 1] = NULL;
    return (result);
}

text split_str_max(cstring str, char spliter, ksize_t nb_splits) {
    if (nb_splits <= 0) {
        return split_str(str, spliter);
    }
    text splitted = split_str(str, spliter);
    string str_spliter = empty_str();
    add_char_str(&str_spliter, spliter);
    ksize_t sz_txt = length_text((ctext)splitted);

    for (ksize_t i = sz_txt - 1; i >= nb_splits; i--) {
        concat_str_nm(&splitted[i - 1], str_spliter);
        concat_str_nm(&splitted[i - 1], splitted[i]);
        remove_line_text(&splitted, i);
    }
    kfree(str_spliter);
    return splitted;
}
