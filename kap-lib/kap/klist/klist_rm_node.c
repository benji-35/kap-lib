/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** klist_rm_node
*/

#include <kap/klist.h>
#include <stdlib.h>

void list_remove_node(klist_t *list, int index)
{
    knode_t *node = list_get_inode(list, index);

    if (node == NULL)
        return;
    
}