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