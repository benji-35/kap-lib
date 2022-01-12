/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** init_node_list
*/

#include <kap/kmem.h>
#include <kap/kparser.h>
#include <kap/kutils.h>
#include <stdio.h>

static void rm_all_spaces_start(string *str, ksize_t nb_spaces)
{
    for (ksize_t i = 0; i < nb_spaces; i++)
        str_rm_fchar(str);
}

static void new_path2(ksize_t nb_spaces, text args, text *p_splitted,
    ksize_t nb_nodes) {
    if (nb_spaces == 0) {
        for (ksize_t i = 0; i < nb_nodes - 1; i++)
            remove_line_text(p_splitted, nb_nodes - i);
        kfree((*p_splitted)[0]);
        (*p_splitted)[0] = copy_str(args[0]);
    } else if (nb_nodes == (nb_spaces / YML_SPC) + 1) {
        remove_line_text(p_splitted, nb_nodes);
        add_str_text(p_splitted, length_text((ctext)*p_splitted), args[0]);
    } else {
        if (nb_nodes > (nb_spaces / YML_SPC) + 1) {
            for (ksize_t i = nb_nodes; i >= (nb_spaces / YML_SPC); i--)
                remove_line_text(p_splitted, i);
            add_str_text(p_splitted, length_text((ctext)*p_splitted), args[0]);
        } else {
            add_str_text(p_splitted, length_text((ctext)*p_splitted), args[0]);
        }
    }
}

static void new_path_from_ymltext(string line, string *curr_path)
{
    if (length(line) == 0) {
        return;
    }
    text args = split_str(line, ':');
    ksize_t nb_spaces = nb_fchars(line, ' ');
    rm_all_spaces_start(&args[0], nb_spaces);
    if (length_text((ctext)args) == 1 && nb_fchars(line, ' ') == 0) {
        kfree(*curr_path);
        *curr_path = concat_str("", (cstring)args[0]);
        free_text(args);
        return;
    }
    text p_splitted = split_str((cstring)*curr_path, '.');
    ksize_t nb_nodes = length_text((ctext)p_splitted);
    kfree(*curr_path);
    new_path2(nb_spaces, args, &p_splitted, nb_nodes);
    *curr_path = text_to_str(p_splitted, ".");
    free_text(args);
    free_text(p_splitted);
}

static bool str_contain_readable(cstring str)
{
    for (ksize_t i = 0; i < length(str); i++) {
        if (str[i] >= 65 && str[i] <= 122)
            return true;
    }
    return false;
}

static void manage_line_detect_yml(string *path, string *value, string line)
{
    if (!str_contain_readable((cstring)line))
        return;
    text splitted_line = split_str((cstring)line, ':');

    if (length_text((ctext)splitted_line) <= 0) {
        free_text(splitted_line);
        kfree(*value);
        *value = NULL;
        return;
    }
    new_path_from_ymltext(line, path);
    if (splitted_line[1] != NULL) {
        kfree(*value);
        str_rm_all_fochar(&splitted_line[1], ' ');
        *value = copy_str((cstring)splitted_line[1]);
    }
    free_text(splitted_line);
}

char first_char_after_spacesYML(string str)
{
    char result;
    string cstr = copy_str((cstring)str);

    str_rm_all_fochar(&cstr, ' ');
    result = cstr[0];
    kfree(cstr);
    return result;
}

void init_yml_nodelist(kyml_parser_t *parser)
{
    text readed = kopen_file_t((cstring)parser->path);
    string currPath = empty_str();
    string value = NULL;

    for (ksize_t i = 0; i < length_text((ctext)readed); i++) {
        if (first_char_after_spacesYML(readed[i]) != '#') {
            manage_line_detect_yml(&currPath, &value, readed[i]);
            if (value != NULL) {
                smart_add_yml_node((cstring)currPath, value, parser);
                kfree(value);
                value = NULL;
            }
        }
    }
    free_text(readed);
    kfree(value);
    kfree(currPath);
}