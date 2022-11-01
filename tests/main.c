/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** main
*/

#include <stdio.h>
#include <kap/klib.h>

int main(int ac UNUSED, text av UNUSED)
{
    auto dir = getDirectory("tests");

    auto files = getFiles(dir);

    for (kusize_t i = 0; i < files->size; i++) {
        kfile_t *file = list_get_inode(files, i)->data;
        printf("%s : file type is %d and file extension is %s\n", file->_name, file->_type, file->_ext);
    }

    remove_dir(dir);
    return 0;
}
