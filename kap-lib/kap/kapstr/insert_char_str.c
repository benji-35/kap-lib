/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** insert_char_str
*/

#include <stdlib.h>
#include <kap/kstr.h>

void insert_char_str(string *str, ksize_t position, char c)
{
    ksize_t size = length(*str);
    if (position > size)
        return;
    string new_str = kmalloc(sizeof(char) * (size + 2));
    for (ksize_t i = 0; i < position; i++)
        new_str[i] = (*str)[i];
    for (ksize_t i = position; i < size; i++)
        new_str[i + 1] = (*str)[i];
    new_str[position] = c;
    new_str[size + 1] = 0;
    kfree(*str);
    *str = new_str;
}