/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** find_node_bindentation
*/

#include <kap/kparser.h>

yml_cont_t *flast_nyml_bindex(yml_cont_t **list, ksize_t index)
{
    ksize_t n_index = index - 1;
    ksize_t size = nb_yml_content(list);

    if (index == 0) {
        if (size == 0)
            return NULL;
        return list[size - 1];
    }
    if (size == 0)
        return NULL;
    return (flast_nyml_bindex(list[size - 1], n_index));
}

yml_cont_t *find_last_yml_node_by_index(kyml_p *parser, ksize_t index)
{
    if (!parser)
        return NULL;
    return (flast_nyml_bindex(parser->content_yml, index));
}