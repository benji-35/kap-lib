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

///Get node from list with its index
///@param list > pointer on the list
///@param data > pointer on data
///@param print > function that can print de value (it can be NULL)
extern void list_add_node(klist_t *list, OBJECT data, void (*print)(OBJECT data));

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

///initialize a new hashmap
///@return hmap > pointer of head of hashmap
extern hmap_t *init_hashmap(void);

///find hash node in hashmap
/// @param hashmap > head of hashmap
/// @param key > the key of node (string)
/// @return khnode if node is found else return NULL
extern khnode_t *find_hashnode(hmap_t *hashmap, string key);

///remove node after found it
/// @param hashmap > head of hashmap
/// @param key > the key of node (string)
extern void remove_hashnode(hmap_t *hashmap, string key);

///clear all hashmap
/// @param hashmap > head of hashmap
extern void clear_hashmap(hmap_t *hashmap);

///add a new hash node in hashmap
///@param hashmap > head of hashmap
///@param key > string that will be the key of the node
///@param value > pointer on variable you want save in hashmap
///@return true if node is added else return false
extern bool add_hashnode(hmap_t *hashmap, string key, OBJECT value);

#endif /*_KHASHMAP_*/

#ifdef __cplusplus
}
#endif

#endif /* !_KAP_LIST_H_ */
