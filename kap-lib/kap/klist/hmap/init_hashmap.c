/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** init_hashmap
*/

#include <kap/kmem.h>
#include <kap/klist.h>

hmap_t *init_hashmap(void)
{
    hmap_t *n_hashmap = kmalloc(sizeof(hmap_t));

    if (n_hashmap == NULL)
        return NULL;
    n_hashmap->len = 0;
    n_hashmap->nodes = NULL;
    return n_hashmap;
}