/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** get_value_yml
*/

#include <kap/kutils.h>
#include <kap/kstr.h>
#include <kap/kparser.h>

string get_value_yml(kyml_p *parser)
{
    string res = NULL;

    kassert(parser == NULL && "parser -> NULL pointer\n");
    if (parser == NULL)
        return (res);
    
}

yml_cont_t *get_last_depth(kyml_p *parser, ksize_t depth)
{
    if (parser == NULL)
        return NULL;
    
}