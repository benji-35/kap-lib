/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** klist
*/

#ifndef _KAP_LIST_H_
#define _KAP_LIST_H_

#include <kap/kutils.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _KLIST_
#define _KLIST_

typedef struct knode_s knode_t;
typedef struct klist_s klist_t;

struct knode_s {
    kusize_t id;
    OBJECT data;
    knode_t *next;
    knode_t *prev;
    void (*print)(OBJECT data);
};

struct klist_s {
    kusize_t size;
    knode_t *list;
};

#endif /*_KLIST_*/

#ifndef _KHASHMAP_
#define _KHASHMAP_

typedef struct khashmap_s khashmap_t;
typedef struct khash_node_s khash_node_t;
typedef khash_node_t khnode_t;
typedef khashmap_t hmap_t;

struct khash_node_s {
    khnode_t *next;
    khnode_t *prev;
    khashmap_t *hashmap;

    string key;
    OBJECT value;
};

struct khashmap_s {
    ksize_t len;
    khnode_t *nodes;
};

#endif /*_KHASHMAP_*/

///Get node from list with its index
///@param list > pointer on the list
///@param data > pointer on data
///@param print > function that can print de value (it can be NULL)
extern void add_node(klist_t *list, OBJECT data, void (*print)(OBJECT data));

///Get node from list with its index
///@param list > pointer on the list
///@param index > index id
///@return node pointer. If node is not found, function return NULL
extern knode_t *list_get_inode(klist_t *list, kusize_t index);

///Clear all list
///@param list > pointer on klist
extern void list_clear(klist_t *list);

///Initiate klist
///@return new klist
extern klist_t *list_init(void);

///Get last hnode in hash map
///@param hmap > hash map that contain hnode to find
///@return khnode > return NULL if an error occured
extern khnode_t *get_last_hnode(hmap_t *hmap);

#ifdef __cplusplus
}
#endif

#endif /* !_KAP_LIST_H_ */
