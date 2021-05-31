/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** split_str_interv
*/

#include <stdlib.h>
#include <kap/kstr.h>
#include <kap/kutils.h>

static ksize_t knb_interv(string str, ksize_t nb)
{
    ksize_t res = 0;
    ksize_t curr = nb;
    ksize_t size = length(str);

    for (ksize_t i = size - 1; i >= 0; i--) {
        curr--;
        if (curr == 0) {
            curr = nb;
            res++;
        }
    }
    res++;
    return (res);
}

static void kcomplete_interv(text splitted, string str, ksize_t nb,\
    ksize_t nb_spl)
{
    ksize_t val_index = 0;

    for (ksize_t i = 0; i < nb_spl; i++) {
        splitted[i] = kmalloc(sizeof(char) * (nb + 1));
        for (int a = 0; a < nb; a++) {
            val_index = i * nb + a;
            splitted[i][a] = str[val_index];
        }
        splitted[i][nb] = 0;
    }
}

text ksplit_interv(string str, ksize_t nb)
{
    if (str == NULL)
        return (NULL);
    ksize_t nb_split = knb_interv(str, nb);
    text splitted = kmalloc(sizeof(string ) * (nb_split));

    kcomplete_interv(splitted, str, nb, nb_split - 1);
    splitted[nb_split - 1] = kmalloc(sizeof(char));
    splitted[nb_split - 1] = NULL;
    return (splitted);
}