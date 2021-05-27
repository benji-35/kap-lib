/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kmemset
*/

#include <kap/kutils.h>

void kmemset(void *__ptr, int __val, ksize_t __size)
{
    uint8_t *__u8 = (uint8_t *)__ptr;

    for (ksize_t i = 0; i < __size; i++)
        __u8[i] = __val;
}