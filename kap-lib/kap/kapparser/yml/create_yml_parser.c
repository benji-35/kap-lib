/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** create_yml_parser
*/

#include <kap/kparser.h>

kyml_p *init_kyml_parser (cstring path) {
    kyml_p *result = kmalloc(sizeof(kyml_p));

    if (result == NULL)
        return result;
    result->path = copy_str(path);
    result->content = kopen_file_t(path);
    result->content_yml.depth = 0;
    result->content_yml.name = NULL;
    result->content_yml.value = NULL;
    return result;
}