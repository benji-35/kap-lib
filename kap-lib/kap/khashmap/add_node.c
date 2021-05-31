/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** add_node
*/

#include <stdlib.h>
#include <kap/kstr.h>
#include <kap/klist.h>

void hmap_add_hnode(hmap_t *hmap, khnode_t *hnode)
{
    khnode_t *klast;
    kassert(hmap == NULL && "[hmap] -> NULL pointer");
    kassert(hnode == NULL && "[hnode] -> NULL pointer");

    if (hmap != KNULL && hnode != KNULL) {
        kassert((klast = get_last_hnode(hmap)) == NULL\
        && "[klast] -> NULL pointer");
        if (klast == NULL)
            return;
        klast->next = hnode;
        hnode->prev = klast;
        hmap->len = hmap->len + 1;
    }
}

void hmap_add(hmap_t *hmap, cstring key, OBJECT data)
{
    khnode_t *n_node;

    kassert(key == NULL && "[key] -> NULL pointer");
    kassert(hmap == NULL && "[hmap] -> NULL pointer");
    kassert((n_node = kmalloc(sizeof(khnode_t))) == NULL);
    if (n_node == NULL || hmap == NULL || key == NULL)
        return;
    n_node->next = NULL;
    n_node->prev = NULL;
    n_node->key = copy_str(key);
    n_node->hashmap = hmap;
    n_node->value = data;
    hmap_add_hnode(hmap, n_node);
}