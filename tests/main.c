/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** main
*/

#include <kap/klib.h>

int main(int ac, text av)
{
    string bin = int_to_bin(1, true);
    printf("(1) bin = %s\n", bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    bin = int_to_bin(5, true);
    printf("(5) bin = %s\n", bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    bin = int_to_bin(12, true);
    printf("(12) bin = %s\n", bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    bin = int_to_bin(32, true);
    printf("(32) bin = %s\n", bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    bin = int_to_bin(64, true);
    printf("(64) bin = %s\n", bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    bin = int_to_bin(66, true);
    printf("(66) bin = %s\n", bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
}