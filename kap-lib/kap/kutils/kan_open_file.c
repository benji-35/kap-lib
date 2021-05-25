/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kan_open_file
*/

#include <kap/kutils.h>
#include <kap/kstr.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

bool_t can_open_file(string path)
{
    int fd = open(path, O_RDONLY, stat);

    if (fd < 0)
        return (false);
    close(fd);
    return (true);
}