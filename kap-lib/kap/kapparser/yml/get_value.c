/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** get_value
*/

#include <kap/kutils.h>
#include <kap/kparser.h>

string get_value_yml(kyml_p *parser, cstring path)
{
    text way = split_str(path, '.');
    

    free_text(way);
}

text get_array_yml(kyml_p *parser, cstring path)
{

}