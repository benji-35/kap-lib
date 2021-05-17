/*
** EPITECH PROJECT, 2021
** C-Strlib
** File description:
** add_line_text
*/

#include <stdlib.h>
#include <kap/kstr.h>

void add_line_ptext(text *txt, int pos)
{
    int size = length_text(*txt);
    text new_text = malloc(sizeof(char *) * (size + 2));

    if (pos >= size)
        pos = size;
    if (pos <= 0)
        pos = 0;
    for (int i = 0; i < pos; i++)
        new_text[i] = copy_str((*txt)[i]);
    for (int i = pos; i < size; i++)
        new_text[i + 1] = copy_str((*txt)[i]);
    new_text[pos] = empty_str();
    new_text[size + 1] = NULL;
    free_text(*txt);
    *txt = new_text;
}

void add_line_text(text *txt)
{
    int size = length_text(*txt);
    text new_text = malloc(sizeof(char *) * (size + 2));

    for (int i = 0; i < size; i++)
        new_text[i] = copy_str((*txt)[i]);
    new_text[size] = empty_str();
    new_text[size + 1] = NULL;
    free_text(*txt);
    *txt = new_text;
}

void add_str_text(text *text, int pos, string str)
{
    if (text == NULL)
        return;
    int size = length_text(*text);
    if (pos >= size)
        pos = size;
    if (pos <= 0)
        pos = 0;
    add_line_ptext(text, pos);
    free((*text)[pos]);
    (*text)[pos] = copy_str(str);
}