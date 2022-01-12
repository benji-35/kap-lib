/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** get_conf_value
*/

#include <kap/kutils.h>
#include <kap/kparser.h>

string get_value_conf(kconf_parser_t *parser, cstring key) {

    string res = copy_str("");
    string keyComplete = concat_str(key, "=");
    for (int i = 0; i < length_text((ctext)parser->content); i++) {
        if (strat_with(parser->content[i], keyComplete)) {
            kfree(res);
            res = copy_str(parser->content[i]);
            remove_ostr_str(&res, keyComplete);
            break;
        }
    }
    return res;
}