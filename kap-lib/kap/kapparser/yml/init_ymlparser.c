/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** init_ymlparser
*/

#include <kap/kmem.h>
#include <kap/kutils.h>
#include <kap/kparser.h>

kyml_parser_t *init_yml_parser(cstring path)
{
    kyml_parser_t *result = NULL;

    if (!can_open_file(path))
        return result;
    kassert((result = kmalloc(sizeof(kyml_parser_t))) == NULL);
    if (result == NULL)
        return result;
    result->path = copy_str(path);
    result->nodeList = NULL;

    init_yml_nodelist(result);
    display_yml_content(result);
    return result;
}

void destroy_yml_parser(kyml_parser_t *parser)
{
    if (parser == NULL)
        return;
    kfree(parser->path);
    knode_yml *node = parser->nodeList;
    knode_yml *tampon;

    while (node != NULL) {
        kfree(node->path);
        kfree(node->value);
        tampon = node->next;
        free_text(node->unixistant_pathes);
        kfree(node);
        node = tampon;
    }
    kfree(parser);
}