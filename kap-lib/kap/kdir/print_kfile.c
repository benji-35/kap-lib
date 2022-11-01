/*
** EPITECH PROJECT, 2022
** C-Lib
** File description:
** print_kfile
*/

#include "kap/kdir.h"
#include "kap/kprintf.h"

void print_kfile(void *data) {
    if (data == NULL)
        return;
    kfile_t *file = (kfile_t *) data;
    kprintf("%s : file type is %d and file extension is %s", file->_name, file->_type, file->_ext);
}
