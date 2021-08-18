/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** quick_yml_node
*/

#include <kap/kutils.h>
#include <kap/kparser.h>

knode_yml *get_last_yml_node(kyml_parser_t *parser)
{
    if (parser == NULL)
        return NULL;
    knode_yml *result = parser->nodeList;

    if (result == NULL)
        return result;
    while (result->next != NULL) {
        result = result->next;
    }
    return result;
}