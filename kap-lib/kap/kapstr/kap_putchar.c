/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kap_putchar
*/

#include <unistd.h>

void kput_char(char c)
{
    write(1, &c, 1);
}