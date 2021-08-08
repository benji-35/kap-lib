/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** clear_hashmap
*/

#include <kap/kmem.h>
#include <kap/klist.h>
#include <kap/kstr.h>

static void remove_mem_hashnode(khnode_t *node)
{
    if (node != NULL) {
        node->hashmap->nodes = node->next;
        kfree(node->key);
        kfree(node);
    }
}

void clear_hashmap(hmap_t *hashmap)
{
    for (ksize_t i = 0; i < hashmap->len; i++) {
        khnode_t *node = hashmap->nodes;
        remove_mem_hashnode(node);
    }
    hashmap->len = 0;
}

void remove_hashnode(hmap_t *hashmap, string key) {
    khnode_t *node = find_hashnode(hashmap, key);
    remove_mem_hashnode(node);
}