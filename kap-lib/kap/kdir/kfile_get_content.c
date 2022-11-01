/*
** EPITECH PROJECT, 2022
** C-Lib
** File description:
** kfile_get_content
*/

#include "kap/kdir.h"
#include "kap/kasserts.h"

static text get_file_conents(cstring path) {
    FILE *file = fopen(path, "r");
    text result = NULL;
    string line = NULL;
    size_t len = 0;
    size_t size = 0;

    if (file == NULL)
        return NULL;
    while (getline(&line, &len, file) != -1) {
        add_str_text(&result, size, line);
        size++;
    }
    fclose(file);
    return result;
}

text get_file_content(kfile_t *file) {
    if (!kassert(file == NULL))
        return NULL;
    if (kassert(file->_type != KFILE)) {
        return NULL;
    }
    return get_file_conents(file->_path);
}
