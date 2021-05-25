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

yml_content_t *create_yml_content(yml_content_t ***list, string name)
{
    yml_content_t *n_content;

    kassert((n_content = malloc(sizeof(yml_content_t))) == NULL);
    if (n_content == NULL)
        return (NULL);
    n_content->name = copy_str(name);
    n_content->content = NULL;
    n_content->value = NULL;
}