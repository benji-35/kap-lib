/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** add_conf_calue
*/

#include <kap/kutils.h>
#include <kap/kparser.h>

PBOOL check_line_conf_add (string line, string key) {
    if (strat_with(line, key))  {
        return true;
    }
    return false;
}

void add_value_conf(kconf_parser_t *parser, cstring key, string value) {
    bool found = false;
    ksize_t sizeTxt = length_text((ctext)parser->content);
    string keyComplete = concat_str(key, "=");

    for (int i = 0; i < sizeTxt; i++) {
        if (check_line_conf_add(parser->content[i], keyComplete)) {
            kfree(parser->content[i]);
            parser->content[i] = concat_str(keyComplete, value);
            found = true;
            break;
        }
    }
    if (!found) {
        concat_str_nm(&keyComplete, (cstring)value);
        add_str_text(&parser->content, sizeTxt, keyComplete);
    }
    if (parser->auto_save) {
        save_conf_parser(parser);
    }
    kfree(keyComplete);
}