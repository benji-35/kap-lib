/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** knode_get
*/

#include <kap/klist.h>
#include <stdlib.h>

knode_t *list_get_inode(klist_t *list, kusize_t index)
{
    if (list == NULL)
        return (NULL);

    knode_t *nd = list->list;

    while (nd != NULL) {
        if (nd->id == index)
            return (nd);
        nd = nd->next;
    }
    return (NULL);
}