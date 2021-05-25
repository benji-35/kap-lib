/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** destroy_yml_parser
*/

#include <stdlib.h>
#include <kap/kutils.h>
#include <kap/kstr.h>
#include <kap/kparser.h>

static void free_content_yml(yml_cont_t **content)
{
    ksize_t i = 0;

    if (content == NULL)
        return;
    for (; content[i]; i++) {
        kfree(content[i]->name);
        kfree(content[i]->value);
        free_content_yml(content[i]->content);
    }
    kfree(content[i + 1]);
    kfree(content);
}

static void destroy_specific_content(yml_cont_t *content)
{
    kfree(content->name);
    kfree(content->value);
    free_content_yml(content->content);
}

void destroy_path_content(kyml_p *parser, string path)
{
    if (parser == NULL || path == NULL)
        return;
    text pathes = split_str(path, '.');
    yml_cont_t *yml = search_content_yml(0, pathes, parser->content_yml);

    destroy_specific_content(yml);
}

void destroy_yml_parser(kyml_p *parser)
{
    if (parser == NULL)
        return;
    kfree(parser->path);
    free_text(parser->content);
    free_content_yml(parser->content_yml);
    kfree(parser);
    parser = KNULL;
}