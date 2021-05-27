/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** check_file_extension
*/

#include <kap/kutils.h>
#include <kap/kstr.h>

bool check_extension_file(string path, string __exten)
{
    bool res = false;
    text sep;
    ksize_t len = 0;

    kassert((sep = split_str(path, '.')) == NULL);
    if (sep == NULL)
        return false;
    kassert((len = length_text(sep)) <= 0);
    if (len <= 0)
        return false;
    if (str_equality(sep[len - 1], __exten))
        res = true;
    free_text(sep);
    return (res);
}