/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** get_last_yml_content
*/

#include <kap/kparser.h>
#include <kap/kutils.h>

yml_content_t *get_last_yml_content(kyml_p *parser)
{
    ksize_t i = 0;

    if (parser->content_yml.content == NULL)
        return NULL;
    while (parser->content_yml.content[i + 1] != NULL) {
        i++;
    }
    return parser->content_yml.content[i];
}