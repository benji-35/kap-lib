/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** save_conf_parser
*/

#include <kap/kutils.h>
#include <kap/kparser.h>

void save_conf_parser(kconf_parser_t *parser) {
    if (parser == NULL ||parser->content == NULL || parser->path == NULL) {
        return;
    }
    kwrite_file_t(parser->path, parser->content, "\n", false);
}