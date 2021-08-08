/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** add_hnode
*/

#include <kap/kmem.h>
#include <kap/kstr.h>
#include <kap/klist.h>

bool add_hashnode(hmap_t *hashmap, string key, OBJECT value)
{
    khnode_t *node = kmalloc(sizeof(khnode_t));

    if (node == NULL)
        return false;
    node->hashmap = hashmap;
    node->key = copy_str(key);
    node->next = hashmap->nodes;
    hashmap->nodes = node;
    if (hashmap->nodes != NULL)
        hashmap->nodes->prev = node;
    node->prev = NULL;
    node->value = value;
    return true;
}