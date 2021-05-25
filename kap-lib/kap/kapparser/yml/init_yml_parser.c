/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** init_yml_parser
*/

#include <stdlib.h>
#include <kap/kparser.h>
#include <kap/kutils.h>
#include <kap/kstr.h>

static void create_sub_node_yml()
{

}

static void read_yml_extension(text txt, ksize_t *line, yml_cont_t **content)
{
    yml_cont_t *created;
    text content_t = get_words(txt[*line]);
    ksize_t len = length_text(content_t);
    if (len <= 0) {
        free_text(content_t);
        return;
    }
    if (str_contains(txt[*line], ":")) {
        created = create_yml_content(&content, content_t[0]);
        if (len == 1) {
            
        } else if (len == 2) {
            created->value = copy_str(content_t[1]);
        } else {
            created->value = create_yml_array(content_t + 1);
        }
    }
}

kyml_p *init_yml_parser(string path)
{
    kyml_p *n_parser;
    ksize_t line = 0;

    if (!check_extension_file(path, "yml"))
        return (KNULL);
    kassert((n_parser = malloc(sizeof(kyml_p))) == KNULL);
    if (n_parser == KNULL)
        return (KNULL);
    n_parser->path = path;
    n_parser->content = kopen_file_t(path);
    read_yml_extension(n_parser->content, &line, n_parser->content_yml);
    return (n_parser);
}