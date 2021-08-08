/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** klist_clear
*/

#include <kap/klist.h>
#include <stdlib.h>

void list_clear(klist_t *list)
{
    knode_t *target = NULL;

    if (list == NULL)
        return;
    for (; list->size > 0; list->size--) {
        target = list_get_inode(list, list->size - 1);
        kfree(target);
    }
}