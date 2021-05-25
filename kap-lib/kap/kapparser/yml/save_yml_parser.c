/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** save_yml_parser
*/

#include <kap/kutils.h>
#include <kap/kstr.h>
#include <kap/kparser.h>
#include <stdlib.h>

static void write_yml_name_cont(text *txt, yml_content_t *content, int id)
{
    int nb_spc = id * YML_SPC;
    string res = empty_str_size(nb_spc);
    string tamp = concat_str(res, content->name);
    
    kfree(res);
    res = concat_str(tamp, ": ");
    add_str_text(txt, length_text(*txt), res);
}

static void write_yml_value(text *txt, yml_content_t *content)
{
    string last_line = NULL;
    if (length_text(*txt) - 1 >= 0)
        last_line = (*txt)[length_text(*txt) - 1];
    kassert(last_line == NULL && "[YML WRITE] last line -> NULL pointer");
    if (last_line == NULL)
        return;
    string res = concat_str(last_line, content->value);

    kfree(last_line);
    last_line = res;
}

static void write_yml_list(int index, yml_content_t **list, text *to_w)
{
    int n_index = index + 1;

    for (ksize_t i = 0; list[i]; i++) {
        write_yml_name_cont(to_w, list[i], index);
        if (list[i]->content == NULL) {
            write_yml_value(to_w, list[i]);
        } else {
            write_yml_list(n_index, list[i]->content, to_w);
        }
    }
}

void save_yml_parser(kyml_p *parser)
{
    text to_write = NULL;
    string write_s;

    write_yml_list(0, parser->content_yml, &to_write);
    write_s = text_to_str(to_write, "\n");
    kwrite_file(parser->path, write_s, false);
    free_text(to_write);
}