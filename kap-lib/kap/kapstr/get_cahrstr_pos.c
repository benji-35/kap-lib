/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** get_cahrstr_pos
*/

#include <kap/kstr.h>

ksize_t pos_char_str(string str, char c)
{
    for (ksize_t i = 0; str[i]; i++) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}