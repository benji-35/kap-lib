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

static void kwrite_append(string path, string txt)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd < 0)
        return;
    write(fd, txt, length(txt));
    close(fd);
}

static void kwrite_noappend(string path, string txt)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0)
        return;
    write(fd, txt, length(txt));
    close(fd);
}

void kwrite_file(string path, string txt, bool append)
{
    if (path == NULL)
        return;
    if (txt == NULL)
        return;
    if (append) {
        kwrite_append(path, txt);
    } else {
        kwrite_noappend(path, txt);
    }
}