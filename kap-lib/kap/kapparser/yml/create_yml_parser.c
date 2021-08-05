/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** create_yml_parser
*/

#include <kap/kparser.h>

static void complete_yml_content(kyml_p *parser)
{
    ksize_t nb_spaces = 0;

    if (parser->path == NULL)
        return;
    for (ksize_t i = 0; i < length_text(parser->content); i++) {
        nb_spaces = nb_fchars(parser->content[i], ' ');
    }
}

static void check_opening_yml(kyml_p *parser)
{
    if (parser->content != NULL)
        return;
    kfree(parser->path);
    kfree(parser);
}

kyml_p *init_kyml_parser(cstring path)
{
    kyml_p *result = kmalloc(sizeof(kyml_p));

    if (result == NULL)
        return result;
    result->path = copy_str(path);
    result->content = kopen_file_t(path);
    result->content_yml.depth = 0;
    result->content_yml.name = NULL;
    result->content_yml.value = NULL;
    result->content_yml.content = NULL;
    check_opening_yml(result);
    complete_yml_content(result);
    return result;
}