/*
** EPITECH PROJECT, 2022
** C-Lib
** File description:
** kfile_get_content
*/

#include "kap/kdir.h"
#include "kap/kasserts.h"

#include <sys/stat.h>
#include <fcntl.h>

static text get_file_conents(cstring path) {
    struct stat st;
    char *buf;
    int rd;
    int fd = open(path, O_RDONLY, stat);
    text result;

    if (fd == -1)
        return NULL;
    stat(path, &st);
    buf = kmalloc_sec(sizeof(char) * (st.st_size + 1));
    rd = read(fd, buf, st.st_size);
    if (rd == -1)
        return NULL;
    buf[st.st_size] = 0;
    close(fd);
    result = split_str(buf, '\n');
    kfree(buf);
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
