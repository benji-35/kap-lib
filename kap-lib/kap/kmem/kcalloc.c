/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kcalloc
*/

#include <stdlib.h>
#include <kap/kmem.h>

void *kcalloc(ksize_t __size)
{
    void *__ptr;

    kassert((__ptr = malloc(__size)) == NULL && "kcalloc failed ->\
    return NULL");
    if (!__ptr)
        return NULL;
    kmemset(__ptr, 0, __size);
    return (__ptr);
}