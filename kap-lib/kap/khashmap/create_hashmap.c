/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** create_hashmap
*/

#include <stdlib.h>
#include <kap/klist.h>

khashmap_t *create_hashmap(void)
{
    khashmap_t *map;

    kassert((map = malloc(sizeof(khashmap_t))) == NULL);
    if (map == NULL)
        return (NULL);
    map->len = 0;
    map->nodes = KNULL;
    return (map);
}