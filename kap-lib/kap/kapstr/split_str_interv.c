/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** split_str_interv
*/

#include <stdlib.h>
#include <kap/kstr.h>
#include <kap/kutils.h>

static int knb_interv(string str, int nb)
{
    int res = 0;
    int curr = nb;
    int size = length(str);

    for (int i = size - 1; i >= 0; i--) {
        curr--;
        if (curr == 0) {
            curr = nb;
            res++;
        }
    }
    res++;
    return (res);
}

static void kcomplete_interv(text splitted, string str, int nb, int nb_spl)
{
    int val_index = 0;

    for (int i = 0; i < nb_spl; i++) {
        splitted[i] = malloc(sizeof(char) * (nb + 1));
        for (int a = 0; a < nb; a++) {
            val_index = i * nb + a;
            splitted[i][a] = str[val_index];
        }
        splitted[i][nb] = 0;
    }
}

text ksplit_interv(string str, int nb)
{
    if (str == NULL)
        return (NULL);
    int nb_split = knb_interv(str, nb);
    text splitted = malloc(sizeof(string ) * (nb_split));

    kcomplete_interv(splitted, str, nb, nb_split - 1);
    splitted[nb_split - 1] = malloc(sizeof(char));
    splitted[nb_split - 1] = NULL;
    return (splitted);
}