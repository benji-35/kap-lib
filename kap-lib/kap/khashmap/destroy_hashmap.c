/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** destroy_hashmap
*/

#include <kap/klist.h>

void destroy_hnode(khnode_t *node)
{
    kassert(node == NULL && "[khnode] -> NULL pointer");
    if (node == NULL)
        return;
    if (node->prev == NULL) {
        node->hashmap->nodes = NULL;
        if (node->next != NULL)
            node->hashmap->nodes = node->next;
        node->hashmap->len = node->hashmap->len - 1;
    } else {
        if (node->next != NULL) {
            node->prev->next = node->next;
        } else {
            node->prev->next = NULL;
        }
    }
    kfree(node->key);
    kfree(node);
}

void destroy_hashmap(hmap_t *hmap)
{
    kassert(hmap == NULL && "[hmap] -> NULL pointer");
    if (hmap == NULL)
        return;
    while (hmap->nodes != KNULL)
        destroy_hnode(hmap->nodes);
    kfree(hmap);
}