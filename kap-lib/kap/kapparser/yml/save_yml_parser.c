/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** save_yml_parser
*/

#include <kap/kutils.h>
#include <kap/kparser.h>
#include <kap/kprintf.h>

static string gen_have_to_addYML(text path_splitted, text hta)
{
    string res = empty_str();
    for (ksize_t i = 0; i < length_text((ctext)path_splitted); i++) {
        for (ksize_t math = 0; math < length_text((ctext)hta); math++) {
            if (str_equality(path_splitted[i], hta[math])) {
                for (ksize_t spaces = 0; spaces < (YML_SPC * (i)); spaces++) {
                    concat_str_nm(&res, " ");
                }
                concat_str_nm(&res, hta[math]);
                concat_str_nm(&res, ":\n");
                break;
            }
        }
    }
    return res;
}

static string gen_yml_endsentece(text path_splitted, cstring value,
    text have_to_add)
{
    string res = empty_str();
    ksize_t nb_points = length_text((ctext)path_splitted) - 1;
    string hta = gen_have_to_addYML(path_splitted, have_to_add);

    concat_str_nm(&res, hta);
    kfree(hta);
    if (nb_points < 0)
        nb_points = 0;
    for (ksize_t i = 0; i < nb_points; i++)
        concat_str_nm(&res, "  ");
    concat_str_nm(&res, path_splitted[nb_points]);
    if (value != NULL) {
        concat_str_nm(&res, ": ");
        concat_str_nm(&res, value);
    }
    concat_str_nm(&res, "\n");
    return res;
}

void save_yml_parser(kyml_parser_t *parser)
{
    knode_yml *node;
    text path_splitted = NULL;
    string res_sent = NULL;

    if (parser == NULL)
        return;
    kclear_file(parser->path);
    node = parser->nodeList;
    while (node) {
        path_splitted = split_str(node->path, '.');
        res_sent = gen_yml_endsentece(path_splitted, node->value,
            node->unixistant_pathes);
        kwrite_file(parser->path, res_sent, true);
        kfree(res_sent);
        node = node->next;
        free_text(path_splitted);
    }
}

void save_yml_parser_of(kyml_parser_t *parser, cstring path)
{
    if (parser == NULL || path == NULL)
        return;

    string tampon_path = parser->path;
    parser->path = copy_str(path);
    save_yml_parser(parser);
    kfree(parser->path);
    parser->path = tampon_path;
}