/*
** EPITECH PROJECT, 2022
** C-Lib
** File description:
** kdir_init
*/

#include "kap/kasserts.h"
#include "kap/kdir.h"

kdir_t *getDirectory(cstring path) {
    kdir_t *result = kmalloc_sec(sizeof(kdir_t));

    result->_path = copy_str(path);
    result->_content = list_init();
    update_dir(result);
    return result;
}

void remove_dir(kdir_t *dir) {
    if (dir != NULL) {
        kfree(dir->_path);
    }
    for (kusize_t i = 0; i < dir->_content->size; i++) {
        remove_file((kfile_t *)list_get_inode(dir->_content, i)->data);
    }
    list_clear(dir->_content);
    kfree(dir->_content);
    kfree(dir);
}

klist_t *getFiles(kdir_t *dir) {
    klist_t *result = list_init();
    kfile_t *file = NULL;

    for (kusize_t i = 0; i < dir->_content->size; i++) {
        file = list_get_inode(dir->_content, i)->data;
        if (file->_type == KFILE)
            list_add_node(result, file, NULL);
    }
    return result;
}
