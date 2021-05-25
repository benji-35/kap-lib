/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** set_value
*/

#include <kap/kparser.h>
#include <kap/kstr.h>
#include <kap/kutils.h>

static yml_content_t *search_content_yml(int id, text txt, yml_content_t **li);

static yml_content_t *calc_content_yml(int id, text txt, yml_content_t *yml)
{
    int n_id = id + 1;
    if (id < length_text(txt) - 1)
        return (search_content_yml(n_id, txt, yml->content));
    if (id >= length_text(txt))
        return (NULL);
    return (yml);
}

yml_content_t *search_content_yml(int id, text txt, yml_content_t **li)
{
    if (li == NULL)
        return (calc_content_yml(id, txt, create_yml_content(&li, txt[id])));
    for (ksize_t i = 0; li[i] != KNULL; i++) {
        if (str_equality(li[i]->name, txt[id])) {
            return (calc_content_yml(id, txt, li[i]));
        }
    }
    return (calc_content_yml(id, txt, create_yml_content(&li, txt[id])));
}

void set_value(kyml_p *parser, string path, string value)
{
    text contents = split_str(path, '.');
    yml_content_t *tgt = search_content_yml(0, contents, parser->content_yml);

    kfree(tgt->value);
    tgt->value = value;
}