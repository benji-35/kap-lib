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
    string hex = int_to_hex(1, true);
    string hex_bin = bin_to_hex(bin, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s\n", bin, hex, hex_bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);


    bin = int_to_bin(5, true);
    hex = int_to_hex(5, true);
    hex_bin = bin_to_hex(bin, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s\n", bin, hex, hex_bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);


    bin = int_to_bin(12, true);
    hex = int_to_hex(12, true);
    hex_bin = bin_to_hex(bin, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s\n", bin, hex, hex_bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);


    bin = int_to_bin(32, true);
    hex = int_to_hex(32, true);
    hex_bin = bin_to_hex(bin, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s\n", bin, hex, hex_bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);


    bin = int_to_bin(64, true);
    hex = int_to_hex(64, true);
    hex_bin = bin_to_hex(bin, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s\n", bin, hex, hex_bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);


    bin = int_to_bin(66, true);
    hex = int_to_hex(66, true);
    hex_bin = bin_to_hex(bin, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s\n", bin, hex, hex_bin);
    printf("int value = %d\n", bin_to_int(bin, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);
}