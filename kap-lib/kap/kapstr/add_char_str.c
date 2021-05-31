/*
** EPITECH PROJECT, 2021
** C-Strlib
** File description:
** add_char_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

void add_char_str(string *str, char c)
{
    ksize_t size = length(*str);
    char *new_str = kmalloc(sizeof(char) * (size + 2));

    for (ksize_t i = 0; i < size; i++)
        new_str[i] = (*str)[i];
    new_str[size] = c;
    new_str[size + 1] = 0;
    kfree(*str);
    *str = new_str;
}

void add_char_strp(string *str, char c, ksize_t pos)
{
    ksize_t size = length(*str);
    char *new_str;

    if (pos > size)
        pos = size;
    if (pos < 0)
        pos = 0;
    new_str = kmalloc(sizeof(char) * (size + 2));
    for (ksize_t i = 0; i < pos; i++)
        new_str[i] = (*str)[i];
    for (ksize_t i = pos; i < size; i++)
        new_str[i + 1] = (*str)[i];
    new_str[pos] = c;
    new_str[size + 1] = 0;
    kfree(*str);
    *str = new_str;
}

void remove_char_str(string *str, ksize_t pos)
{
    ksize_t size = length(*str);
    if (pos < 0 || pos >= size)
        return;
    char *new_str = kmalloc(sizeof(char) * (size));
    for (ksize_t i = 0; i < pos; i++)
        new_str[i] = (*str)[i];
    for (ksize_t i = pos + 1; i < size; i++)
        new_str[i - 1] = (*str)[i];
    new_str[size - 1] = 0;
    kfree(*str);
    *str = new_str;
}