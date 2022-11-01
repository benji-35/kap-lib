/*
** EPITECH PROJECT, 2022
** C-Lib
** File description:
** kfile_remove
*/

#include "kap/kasserts.h"
#include "kap/kdir.h"

void remove_file(kfile_t *file) {
    if (kassert(file == NULL))
        return;
    kfree(file->_name);
    kfree(file->_path);
    kfree(file->_ext);
    kfree(file);
}
