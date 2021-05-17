/*
** EPITECH PROJECT, 2021
** C-Strlib
** File description:
** remove_line_text
*/

#include <stdlib.h>
#include <kap/kstr.h>

void remove_line_text(text *txt, int pos)
{
    if (*txt == NULL)
        return;
    int size = length_text(*txt);
    int curr = 0;
    if (pos < 0)
        pos = 0;
    if (pos >= size)
        pos = size - 1;
    text new_text = malloc(sizeof(char *) * (size));
    for (int i = 0; i < size; i++) {
        if (i == pos) {
            curr++;
        } else {
            new_text[i - curr] = copy_str((*txt)[i]);
        }
    }
    new_text[size - 1] = NULL;
    free_text(*txt);
    *txt = new_text;
}

void remove_line_text_string(text *txt, string str)
{
    for (int i = 0; (*txt)[i] != NULL; i++) {
        if (str_contains((*txt)[i], str)) {
            remove_line_text(txt, i);
            remove_line_text_string(txt, str);
            break;
        }
    }
}