/*
** EPITECH PROJECT, 2021
** C-Strlib
** File description:
** replace_str_char
*/

#include <stdlib.h>
#include <kap/kstr.h>

void replace_char_str(string str, char target, char replace)
{
    for (ksize_t i = 0; str[i]; i++) {
        if (str[i] == target)
            str[i] = replace;
    }
}

void replace_char_text(text txt, char target, char replace)
{
    for (ksize_t i = 0; txt[i] != NULL; i++)
        replace_char_str(txt[i], target, replace);
}