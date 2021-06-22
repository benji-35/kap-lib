/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** remove_all_fochar
*/

#include <kap/kstr.h>

void str_rm_all_fochar(string *str, char c)
{
    while ((*str)[0] == c)
        str_rm_fchar(str);
}