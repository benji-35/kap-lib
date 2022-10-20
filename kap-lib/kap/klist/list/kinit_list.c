/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kinit_list
*/

#include <kap/klist.h>
#include <stdlib.h>

klist_t *list_init(void)
{
    klist_t *res = kmalloc(sizeof(klist_t));

    if (res == NULL)
        return (res);
    res->list = NULL;
    res->size = 0;
    return (res);
}

klist_t *list_copy(klist_t *list) {
    klist_t *result = NULL;
    if (list == NULL)
        return result;
    result = kmalloc_sec(sizeof(klist_t));

    for (kusize_t i = 0; i < list->size; i++) {
        knode_t *node = list_get_inode(list, i);
        list_add_node(result, node->data, node->print);
    }
    return result;
}
