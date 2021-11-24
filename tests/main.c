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
    /*string bin = int_to_bin(1, true);
    string hex = int_to_hex(1, true);
    string hex_bin = bin_to_hex(bin, true, true);
    string bin_hex = hex_to_bin(hex, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s, bin_hex = %s\n", bin, hex, hex_bin, bin_hex);
    printf("int value = %d, int_hex value = %d\n", bin_to_int(bin, true), hex_to_int(hex, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);
    kfree(bin_hex);


    bin = int_to_bin(5, true);
    hex = int_to_hex(5, true);
    hex_bin = bin_to_hex(bin, true, true);
    bin_hex = hex_to_bin(hex, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s, bin_hex = %s\n", bin, hex, hex_bin, bin_hex);
    printf("int value = %d, int_hex value = %d\n", bin_to_int(bin, true), hex_to_int(hex, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);
    kfree(bin_hex);


    bin = int_to_bin(12, true);
    hex = int_to_hex(12, true);
    hex_bin = bin_to_hex(bin, true, true);
    bin_hex = hex_to_bin(hex, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s, bin_hex = %s\n", bin, hex, hex_bin, bin_hex);
    printf("int value = %d, int_hex value = %d\n", bin_to_int(bin, true), hex_to_int(hex, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);
    kfree(bin_hex);


    bin = int_to_bin(32, true);
    hex = int_to_hex(32, true);
    hex_bin = bin_to_hex(bin, true, true);
    bin_hex = hex_to_bin(hex, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s, bin_hex = %s\n", bin, hex, hex_bin, bin_hex);
    printf("int value = %d, int_hex value = %d\n", bin_to_int(bin, true), hex_to_int(hex, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);
    kfree(bin_hex);


    bin = int_to_bin(64, true);
    hex = int_to_hex(64, true);
    hex_bin = bin_to_hex(bin, true, true);
    bin_hex = hex_to_bin(hex, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s, bin_hex = %s\n", bin, hex, hex_bin, bin_hex);
    printf("int value = %d, int_hex value = %d\n", bin_to_int(bin, true), hex_to_int(hex, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);
    kfree(bin_hex);


    bin = int_to_bin(66, true);
    hex = int_to_hex(66, true);
    hex_bin = bin_to_hex(bin, true, true);
    bin_hex = hex_to_bin(hex, true, true);
    printf("(1) bin = %s, hex = %s, hex_bin = %s, bin_hex = %s\n", bin, hex, hex_bin, bin_hex);
    printf("int value = %d, int_hex value = %d\n", bin_to_int(bin, true), hex_to_int(hex, true));
    kfree(bin);
    kfree(hex);
    kfree(hex_bin);
    kfree(bin_hex);*/
    kyml_parser_t *parser = init_yml_parser("tests/parser_files/test.yml");
    if (parser == NULL) {
        kprintf("Error while init parser -> returned NULL\n");
        return 84;
    }
    set_value_YML("content.content1", "finalContent", parser);
    string val = get_value_YML("clans.allezLeFoot.color", parser);
    printf("\n[MAIN] value of allezLeFoot Color : %s\n", val);
    if (val == NULL) {
        printf("[MAIN] creation du path avec la valeur initiale\n");
        set_value_YML("clans.allezLeFoot.color", "Init value", parser);
    } else {
        set_value_YML("clans.allezLeFoot.color", "\"&2\"", parser);
    }
    printf("\n");
    display_yml_content(parser);
    save_yml_parser(parser);
    destroy_yml_parser(parser);
    return 0;
}