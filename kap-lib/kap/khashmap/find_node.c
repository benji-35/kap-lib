/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** find_node
*/

#include <kap/klist.h>

khnode_t *get_last_hnode(hmap_t *hmap)
{
    khnode_t *node;

    kassert(hmap == NULL && "[hmap] -> NULL pointer");
    kassert(hmap->len <= 0 && "[hmap] -> no nodes in hash map");
    if (hmap == NULL || hmap->len <= 0)
        return NULL;
    kassert(hmap->nodes == NULL && "[node in hmap] -> NULL pointer");
    if (hmap->nodes == NULL)
        return NULL;
    node = hmap->nodes;
    while (node->next != NULL)
        node = node->next;
    return (node);
}

khnode_t *get_hnode_index(hmap_t *hmap, ksize_t index)
{
    khnode_t *node;

    kassert(hmap == NULL && "[hmap] -> NULL pointer");
    kassert(hmap->len <=index  && "[hmap] ->\
    no nodes in hash map or not enough nodes");
    if (hmap == NULL || hmap->len <= index)
        return NULL;
    kassert(hmap->nodes == NULL && "[node in hmap] -> NULL pointer");
    if (hmap->nodes == NULL)
        return NULL;
    node = hmap->nodes;
    for (ksize_t i = 1; i < index; i++)
        node = node->next;
    return (node);
}