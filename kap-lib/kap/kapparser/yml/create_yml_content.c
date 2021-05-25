/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** create_yml_content
*/

#include <stdlib.h>
#include <kap/kparser.h>
#include <kap/kstr.h>
#include <kap/kutils.h>

bool resize_yml_list_cont(ksize_t size, yml_cont_t ***curr)
{
    ksize_t curr_s = nb_yml_content(*curr);
    yml_cont_t **n_list;

    kassert((n_list = malloc(sizeof(size + 1))) == NULL);
    if (n_list == NULL)
        return (false);
    for (ksize_t i = 0; i < size; i++) {
        n_list[i] = NULL;
        if (i < curr_s) {
            n_list[i] = (*curr)[i];
        }
    }
    kfree((*curr)[curr_s]);
    kfree(*curr);
    *curr = curr_s;
    return (true);
}

yml_content_t *create_yml_content(yml_content_t ***list, string name)
{
    yml_content_t *n_content;
    ksize_t nb_contents = nb_yml_content(*list);

    kassert((n_content = malloc(sizeof(yml_content_t))) == NULL);
    if (n_content == NULL)
        return (NULL);
    n_content->name = copy_str(name);
    n_content->content = NULL;
    n_content->value = NULL;
    if (resize_yml_list_cont(nb_contents + 1, list))
        (*list)[nb_contents] = n_content;
}