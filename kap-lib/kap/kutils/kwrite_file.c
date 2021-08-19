/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kwrite_file
*/

#include <stdlib.h>
#include <kap/kutils.h>
#include <kap/kstr.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static void kwrite_append(cstring path, cstring txt)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd < 0)
        return;
    write(fd, txt, length(txt));
    close(fd);
}

static void kwrite_noappend(cstring path, cstring txt)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0)
        return;
    write(fd, txt, length(txt));
    close(fd);
}

void kwrite_file_t(string path, text txt, cstring sep, bool append)
{
    string str = NULL;

    if (path == NULL)
        return;
    if (txt == NULL)
        return;
    str = text_to_str(txt, sep);
    if (append) {
        kwrite_append(path, str);
    } else {
        kwrite_noappend(path, str);
    }
    kfree(str);
}

void kwrite_file(cstring path, cstring content, bool append)
{
    if (path == NULL)
        return;
    if (content == NULL)
        return;
    if (append) {
        kwrite_append(path, content);
    } else {
        kwrite_noappend(path, content);
    }
}

void kclear_file(cstring path)
{
    kwrite_file(path, "", false);
}