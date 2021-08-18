/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** save_yml_parser
*/

#include <kap/kutils.h>
#include <kap/kparser.h>
#include <kap/kprintf.h>

void save_yml_parser(kyml_parser_t *parser)
{
    if (!can_open_file(parser->path)) {
        kfprintf(2, "We can't write in this file : %s\n", parser->path);
        return;
    }
    
}