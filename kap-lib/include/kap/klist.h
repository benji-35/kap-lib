/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** klist
*/

#ifndef KLIST_H_
#define KLIST_H_

#include <kap/kutils.h>

typedef struct knode_s knode_t;
typedef struct klist_s klist_t;

struct knode_s {
    kusize_t id;
    void *data;
    knode_t *next;
    knode_t *prev;
    void (*print)(void *data);
};

struct klist_s {
    kusize_t size;
    knode_t *list;
};

///Get node from list with its index
///@param list > pointer on the list
///@param data > pointer on data
///@param print > function that can print de value (it can be NULL)
void add_node(klist_t *list, void *data, void (*print)(void *data));

///Get node from list with its index
///@param list > pointer on the list
///@param index > index id
///@return node pointer. If node is not found, function return NULL
knode_t *list_get_inode(klist_t *list, kusize_t index);

///Clear all list
///@param list > pointer on klist
void list_clear(klist_t *list);

///Initiate klist
///@return new klist
klist_t *list_init(void);

#endif /* !KLIST_H_ */
