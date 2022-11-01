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
    auto dir = init_yml_parser("tests/test.yml");

    get_yml_node("path", dir)->value;

    return 0;
}
