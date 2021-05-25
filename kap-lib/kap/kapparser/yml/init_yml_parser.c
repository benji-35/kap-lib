/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** init_yml_parser
*/

#include <stdlib.h>
#include <kap/kparser.h>
#include <kap/kutils.h>

kyml_p *init_yml_parser(string path)
{
    kyml_p *n_parser;

    kassert((n_parser = malloc(sizeof(kyml_p))) == KNULL);
    if (n_parser == KNULL)
        return (KNULL);
    n_parser->path = path;
    n_parser->content = kopen_file_t(path);
    return (n_parser);
}