/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kmalloc
*/

#include <stdlib.h>
#include <kap/kmem.h>

void *kmalloc(ksize_t __size)
{
    void *res;

    kassert((res = malloc(__size)) == NULL && "kmalloc failed\n");
    return res;
}

void *kmalloc_sec(ksize_t __size)
{
    void *res;

    keassert((res = malloc(__size)) == NULL && "kmalloc failed\n");
    return res;
}