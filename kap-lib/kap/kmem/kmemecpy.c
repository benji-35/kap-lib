/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kmemecpy
*/

#include <kap/kmem.h>

void *kmemcpy(void *__ptr, void *__src, ksize_t __size)
{
    uint8_t *_ptrv;
    uint8_t *_ptrs;

    if (!__ptr || !__src || !__size)
        return NULL;
    _ptrv = (uint8_t *)__ptr;
    _ptrs = (uint8_t *)__src;
    for (ksize_t i = 0; i < __size; i++)
        *(_ptrv + i) = *(_ptrs + i);
    return (__ptr);
}