/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** node_exists
*/

#include <kap/kutils.h>
#include <kap/kparser.h>

bool node_yml_exists(cstring path, kyml_parser_t *parser)
{
    if (parser == NULL)
        return false;
    knode_yml *node = parser->nodeList;
    while (node) {
        if (str_equality(node->path, path))
            return true;
        node = node->next;
    }
    return false;
}

knode_yml *get_yml_node(cstring path, kyml_parser_t *parser)
{
    if (!node_yml_exists(path, parser))
        return NULL;
    knode_yml *node = parser->nodeList;
    while (node) {
        if (str_equality(node->path, path))
            return node;
        node = node->next;
    }
    return NULL;
}