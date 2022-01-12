/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** init_kconf
*/

#include <kap/kutils.h>
#include <kap/kparser.h>

kconf_parser_t *init_kconf_parser(cstring path) {
    kconf_parser_t *parser = kmalloc(sizeof(kconf_parser_t));

    if (parser == NULL) {
        return NULL;
    }
    parser->path = copy_str(path);
    parser->content = kopen_file_t(path);
    parser->auto_save = true;
    return parser;
}

void set_autosave_kconf_parser(kconf_parser_t *parser, bool val_autosave) {
    parser->auto_save = val_autosave;
    save_conf_parser(parser);
}