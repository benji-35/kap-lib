/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** remove_conf_parser
*/

#include <kap/kutils.h>
#include <kap/kparser.h>

void free_conf_parser(kconf_parser_t *parser) {
    save_conf_parser(parser);
    if (parser == NULL) {
        return;
    }
    free_text(parser->content);
    kfree(parser->path);
    kfree(parser);
}