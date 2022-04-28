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
    var coucou = copy_str("Hello World !");
    var txt = split_str(coucou, ' ');

    for (var i = 0; i < length_text(txt); i++) {
        printf("%s\n", txt[i]);
    }

    free_text(txt);
    kfree(coucou);

    return 0;
}