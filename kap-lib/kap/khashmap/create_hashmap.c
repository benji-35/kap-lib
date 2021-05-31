/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** create_hashmap
*/

#include <stdlib.h>
#include <kap/klist.h>

hmap_t *create_hashmap(void)
{
    hmap_t *map;

    kassert((map = kmalloc(sizeof(hmap_t))) == NULL);
    if (map == NULL)
        return (NULL);
    map->len = 0;
    map->nodes = KNULL;
    return (map);
}