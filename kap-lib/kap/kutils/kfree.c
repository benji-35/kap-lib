/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kfree
*/

#include <stdlib.h>

void kfree(void *__ptr)
{
    if (__ptr == NULL)
        return;
    free(__ptr);
    __ptr = NULL;
}