/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** add_yml_node
*/

#include <kap/kutils.h>
#include <kap/kprintf.h>
#include <kap/kparser.h>

void add_yml_node(cstring path, string value, kyml_parser_t *parser)
{
    knode_yml *new_node = kmalloc(sizeof(knode_yml));
    knode_yml *last = get_last_yml_node(parser);

    if (new_node == NULL)
        return;
    new_node->prev = last;
    new_node->next = NULL;
    if (last == NULL) {
        parser->nodeList = new_node;
    } else {
        last->next = new_node;
    }
    new_node->master = parser;
    new_node->path = copy_str(path);
    new_node->value = copy_str(value);
    new_node->unixistant_pathes = NULL;
}

void display_yml_content(kyml_parser_t *parser)
{
    if (parser == NULL) {
        kprintf("Parser does not exists\n");
        return;
    }
    knode_yml *node = parser->nodeList;
    while (node != NULL) {
        kprintf("[NODE %p]\n\tpath: %s\n\tcontent: %s\n", node, node->path,
            node->value);
        for (ksize_t i=0; i < length_text((ctext)node->unixistant_pathes); i++)
            kprintf("  Have to create : %s\n", node->unixistant_pathes[i]);
        node = node->next;
    }
    kprintf("end display YML content\n");
}

static void free_node(knode_yml *node)
{
    if (node == NULL)
        return;
    kfree(node->path);
    kfree(node->value);
    if (node->prev == NULL && node->master != NULL) {
        node->master->nodeList = node->next;
    } else {
        node->prev->next = node->next;
    }
    kfree(node);
}

void remove_nodeYML(cstring path, kyml_parser_t *parser)
{
    knode_yml *node = parser->nodeList;
    while (node) {
        if (str_equality(node->path, path)) {
            free_node(node);
            return;
        }
        node = node->next;
    }
}