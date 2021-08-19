/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** set_get_value
*/

#include <kap/kutils.h>
#include <kap/kparser.h>

string get_value_YML(cstring path, kyml_parser_t *parser)
{
    knode_yml *node = parser->nodeList;

    while (node != NULL) {
        if (str_equality(node->path, path))
            return node->value;
        node = node->next;
    }
    return NULL;
}

void set_value_YML(cstring path, string value, kyml_parser_t *parser)
{
    if (parser == NULL || path == NULL)
        return;
    smart_add_yml_node(path, value, parser);
}

void set_array_YML(cstring path, text values, kyml_parser_t *parser)
{
    string tamp;
    string n_value = text_to_str(values, ", ");
    concat_str_nm(&n_value, "]");
    tamp = concat_str("[", n_value);
    set_value_YML(path, n_value, parser);
    kfree(tamp);
    kfree(n_value);
}