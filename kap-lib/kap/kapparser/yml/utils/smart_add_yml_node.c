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
    ksize_t last_max = 0;
    knode_yml *node_max = NULL;
    knode_yml *node = parser->nodeList;

    while (node != NULL) {
        cnode_pathes = split_str(node->path, '.');
        for (ksize_t i = 0; i < length_text((ctext)inputs) - 1; i++) {
            if (i < length_text((ctext)cnode_pathes) &&
                str_equality(cnode_pathes[i], inputs[i])) {
                nb_max++;
            }
        }
        if (nb_max > last_max) {
            node_max = node;
            last_max = nb_max;
        }
        node = node->next;
        free_text(cnode_pathes);
        nb_max = 0;
    }
    return node_max;
}

static void init_unset_yml_pathes(knode_yml *n_node, knode_yml *node_prev)
{
    text p_splitted = split_str(n_node->path, '.');
    text prev_splitted = split_str(node_prev->path, '.');
    ksize_t size_prev = length_text((ctext)prev_splitted);
    ksize_t size_path = length_text((ctext)p_splitted);

    n_node->unixistant_pathes = NULL;
    if (size_path > size_prev) {
        for (ksize_t i = size_prev - 1; i < size_path - 1; i++) {
            add_str_text(&n_node->unixistant_pathes,
                length_text((ctext)n_node->unixistant_pathes), p_splitted[i]);
        }
    }
    free_text(p_splitted);
    free_text(prev_splitted);
}

static void add_ymlNode_spec(knode_yml *node_prev, cstring value,
    kyml_parser_t *parser, cstring path)
{
    knode_yml *n_node = kmalloc(sizeof(knode_yml));
    n_node->master = parser;
    n_node->value = copy_str(value);
    n_node->path = copy_str(path);
    n_node->unixistant_pathes = NULL;
    if (node_prev == NULL) {
        n_node->unixistant_pathes = split_str(path, '.');
        remove_line_text(&n_node->unixistant_pathes,
            length_text((ctext)n_node->unixistant_pathes));
        n_node->prev = NULL;
        n_node->next = parser->nodeList;
        parser->nodeList = n_node;
    } else {
        n_node->prev = node_prev;
        n_node->next = node_prev->next;
        if (n_node->next != NULL)
            n_node->next->prev = n_node;
        node_prev->next = n_node;
        init_unset_yml_pathes(n_node, node_prev);
    }
}

void smart_add_yml_node(cstring path UNUSED, string value UNUSED,
    kyml_parser_t *parser UNUSED)
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