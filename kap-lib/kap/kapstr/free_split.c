/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** free_split
*/

#include <stdlib.h>
#include <kap/kstr.h>

void free_text(text split)
{
    ksize_t u = 0;

    if (split == NULL)
        return;
    for (ksize_t i = 0; split[i] != NULL; i++) {
        u = i;
        kfree(split[i]);
    }
    kfree(split[u + 1]);
    kfree(split);
}