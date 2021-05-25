/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** yml_format
*/

#include <kap/kutils.h>
#include <kap/kstr.h>
#include <kap/kparser.h>

string create_yml_array(text txt)
{
    string tampon = NULL;
    string res = copy_str("[");

    for (ksize_t i = 0; txt[i]; i++) {
        tampon = concat_str(res, txt[i]);
        kfree(res);
        if (txt[i + 1]) {
            res = concat_str(tampon, ",");
            kfree(tampon);
        }
    }
    res = concat_str(tampon, "]");
    kfree(tampon);
    return (res);
}

ksize_t nb_yml_content(yml_cont_t **cont)
{
    ksize_t res = 0;

    if (cont != NULL)
        for (; cont[res]; res++);
    return (res);
}