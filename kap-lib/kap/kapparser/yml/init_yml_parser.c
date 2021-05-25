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

static void sub_init_yml(yml_cont_t *cont, text txt, int *line)
{
    int theorics = cont->depth * YML_SPC;

    if (!contain_only_char_tp(txt[*line], ' ', theorics));
        return;
    
}

static yml_cont_t *read_yml_extension(text txt, ksize_t *line, yml_cont_t **cont, ksize_t depth)
{
    ksize_t n_line = *line + 1;
    yml_cont_t *created;
    text cont_t = get_words(txt[*line]);
    ksize_t len = length_text(cont_t);
    if (len <= 0) {
        free_text(cont_t);
        return;
    }
    if (str_contains(txt[*line], ":")) {
        created = create_yml_content(&cont, cont_t[0], depth);
        if (len == 1) {
            sub_init_yml(created, txt, n_line);
        } else if (len == 2) {
            created->value = copy_str(cont_t[1]);
        } else {
            created->value = create_yml_array(cont_t + 1);
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
    read_yml_extension(n_parser->content, &line, n_parser->content_yml, 0);
    return (n_parser);
}