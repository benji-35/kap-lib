/*
** EPITECH PROJECT, 2022
** C-Lib
** File description:
** kdir_update
*/

#include "kap/kdir.h"
#include "kap/kasserts.h"

#include <sys/stat.h>
#include <dirent.h>

static string get_file_ext(cstring path) {
    string result = NULL;
    bool found = false;

    for (ksize_t i = 0; i < length(path); i++) {
        if (path[i] == '.')
            found = true;
        if (found)
            add_char_str(&result, path[i]);
    }
    return result;
}

static kfile_type_t get_file_type(cstring path) {
    struct stat path_stat;
    stat(path, &path_stat);
    if (S_ISDIR(path_stat.st_mode))
        return KDIR;
    if (S_ISREG(path_stat.st_mode))
        return KFILE;
    if (S_ISLNK(path_stat.st_mode))
        return KLINK;
    if (S_ISCHR(path_stat.st_mode))
        return KEXEC;
    if (S_ISSOCK(path_stat.st_mode))
        return KSOCKET;
    if (S_ISFIFO(path_stat.st_mode))
        return KPIPE;
    return KUNKNOWN;
}

void update_dir(kdir_t *dir) {
    if (kassert(dir == NULL))
        return;
    DIR *d = opendir(dir->_path);
    struct dirent *sdir = NULL;
    kfile_t *file = NULL;

    if (d == NULL)
        return;
    while ((sdir = readdir(d)) != NULL) {
        file = kmalloc_sec(sizeof(kfile_t));
        file->_name = copy_str(sdir->d_name);
        file->_path = concat_str(dir->_path, "/");
        concat_str_nm(&file->_path, sdir->d_name);
        file->_ext = get_file_ext(file->_path);
        file->_type = get_file_type(file->_path);
        list_add_node(dir->_content, file, &print_kfile);
    }
    closedir(d);
}
