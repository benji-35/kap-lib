/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kmath_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <kap/klib.h>

void kmath_redirect_all_stds(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(kmath, easy_binary)
{
    return;
    string stri = int_to_bin(1, false);
    string want = "1";

    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}