/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kap_putchar
*/

#include <unistd.h>

void kput_char(char c, int fd)
{
    write(fd, &c, 1);
}