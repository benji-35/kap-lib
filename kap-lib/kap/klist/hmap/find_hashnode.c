/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** find_hashnode
*/

#include <kap/kmem.h>
#include <kap/kstr.h>
#include <kap/klist.h>

khnode_t *find_hashnode(hmap_t *hashmap, string key)
{
    khnode_t *node = hashmap->nodes;
    while (node != NULL) {
        if (str_equality(key, node->key))
            return node;
    }
    return NULL;
}