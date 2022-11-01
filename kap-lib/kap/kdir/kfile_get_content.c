/*
** EPITECH PROJECT, 2022
** C-Lib
** File description:
** kfile_get_content
*/

#include "kap/kdir.h"
#include "kap/kasserts.h"
#include "kap/kprintf.h"

#include <sys/stat.h>
#include <fcntl.h>

static string get_file_conent_string(cstring path) {
    string result = NULL;
    int fd = open(path, O_RDONLY);
    struct stat st;

    if (fd == -1)
        return NULL;
    stat(path, &st);
    result = kmalloc_sec(sizeof(char) * (st.st_size + 1));
    if (read(fd, result, st.st_size) == -1) {
        kfree(result);
        return NULL;
    }
    result[st.st_size] = '\0';
    close(fd);
    return result;
}

static text get_file_content_text(cstring path) {
    text result;
    string str = get_file_conent_string(path);

    if (str == NULL)
        return NULL;
    result = split_str(str, '\n');
    kfree(str);
    return result;
}

text get_file_content(kfile_t *file) {
    if (kassert(file == NULL))
        return NULL;
    if (kassert(file->_type != KFILE)) {
        return NULL;
    }
    return get_file_content_text(file->_path);
}
