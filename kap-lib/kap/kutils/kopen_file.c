/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kopen_file
*/

#include <kap/kstr.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

string kopen_file(string path)
{
    string res = NULL;
    struct stat st;
    ssize_t rd;
    int fd = open(path, O_RDONLY, stat);

    if (fd < 0)
        return (res);
    stat(path, &st);
    res = malloc(sizeof(char) * (st.st_size + 1));
    rd = read(fd, res, st.st_size);
    close(fd);
    if (rd < 0) {
        free(res);
        return (NULL);
    }
    res[st.st_size] = 0;
    return (res);
}