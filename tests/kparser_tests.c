/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kparser_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <kap/klib.h>


Test(kparser_config_file, get_value_one)
{
    string want = "Hello World !";
    kconf_parser_t *parser = init_kconf_parser("tests/parser_files/test.conf");
    string stri = get_value_conf(parser, "test1");

    cr_assert_str_eq(stri, want, "The result was [%s] but expected [%s]\n", stri, want);
}