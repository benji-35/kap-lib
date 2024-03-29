/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** list_add_node
*/

#include <kap/klist.h>
#include <stdlib.h>

void list_add_node(klist_t *list, OBJECT data, void (*print)(OBJECT data))
{
    knode_t *node = kmalloc(sizeof(knode_t));
    knode_t *last = list->list;

    if (node == NULL)
        return;
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    node->id = list->size;
    node->print = print;
    list->size = list->size + 1;
    if (last == NULL) {
        list->list = node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    node->prev = last;
    last->next = node;
}