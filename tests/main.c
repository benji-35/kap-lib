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
        kprintf("%s : file type is %d and file extension is %s\n", file->_name, file->_type, file->_ext);
        text content = get_file_content(file);

        for (ksize_t j = 0; j < length_text((ctext)content); j++) {
            kprintf(":-- [%s]", content[j]);
        }
        free_text(content);
        kprintf("\n");
    }

    list_clear(files);
    kfree(files);

    remove_dir(dir);
    return 0;
}
