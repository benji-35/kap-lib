/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** destroy_hashmap
*/

#include <kap/klist.h>

void destroy_hnode(khashmap_t *hmap, khnode_t *node)
{
    kassert(hmap == NULL && "[hmap] -> NULL pointer");
    kassert(node == NULL && "[khnode] -> NULL pointer");
    if (hmap == NULL || node == NULL)
        return;
    
}

void destroy_hashmap(khashmap_t *hmap)
{
    kassert(hmap == NULL && "[hmap] -> NULL pointer");
    if (hmap == NULL)
        return;
    
}