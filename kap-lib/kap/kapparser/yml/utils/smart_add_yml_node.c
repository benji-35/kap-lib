/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** smart_add_yml_node
*/

#include <kap/kutils.h>
#include <kap/kprintf.h>
#include <kap/kparser.h>

knode_yml *prev_nodeYML(text inputs, kyml_parser_t *parser)
{
    text cnode_pathes;
    ksize_t nb_max = 0;
    knode_yml *node_max = NULL;
    knode_yml *node = parser->nodeList;
    while (node) {
        cnode_pathes = split_str(node->path, '.');
        for (ksize_t i = 0; i < length_text(inputs); i++) {

        }
        node = node->next;
    }
}

static void add_ymlNode_spec(knode_yml *node_prev, cstring value, kyml_parser_t *parser, cstring path)
{
    knode_yml *n_node = kmalloc(sizeof(knode_yml));
    n_node->master = parser;
    n_node->value = copy_str(value);
    n_node->path = copy_str(path);
    if (node_prev == NULL) {
        n_node->prev = NULL;
        n_node->next = parser->nodeList;
        parser->nodeList = n_node;
    } else {
        n_node->prev = node_prev;
        n_node->next = node_prev->next;
        n_node->next->prev = n_node;
        node_prev->next = n_node;
    }
}

void smart_add_yml_node(cstring path UNUSED, string value UNUSED, kyml_parser_t *parser UNUSED)
{
    text nodes_input;
    knode_yml *node_prev = NULL;
    if (value == NULL) {
        remove_nodeYML(path, parser);
        return;
    }
    if (!str_contains(path, ".")) {
        add_yml_node(path, value, parser);
        return;
    }
    if (node_yml_exists(path, parser)) {
        node_prev = get_yml_node(path, parser);
        kfree(node_prev->value);
        node_prev->value = copy_str(value);
        return;
    }
    nodes_input = split_str(path, '.');
    node_prev = prev_nodeYML(nodes_input, parser);
    add_ymlNode_spec(node_prev, value, parser, path);
    free_text(nodes_input);
}