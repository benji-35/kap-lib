/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kstr_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <kap/klib.h>

void kstr_redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// =========================  TEST STR  =================================//

Test(kstr, add_char_str_test, .init = kstr_redirect_all_stdout)
{
    string stri = "Je suis ben";
    string want = "Je suis ben.";

    add_char_str(&stri, '.');
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
}

Test(kstr, add_char_strp_test, .init = kstr_redirect_all_stdout)
{
    string stri = "e suis ben.";
    string want = "Je suis ben.";

    add_char_strp(&stri, 'J', 0);
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
}

Test(kstr, empty_str_test, .init = kstr_redirect_all_stdout)
{
    string stri = empty_str();
    string want = "\0";

    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
}

Test(kstr, empty_str_size_test, .init = kstr_redirect_all_stdout)
{
    string stri = empty_str_size(1);
    string want = " ";

    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
}

Test(kstr, rm_char_str_test, .init = kstr_redirect_all_stdout)
{
    string stri = "JJe";
    string want  = "Je";

    remove_char_str(&stri, 0);
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
}

Test(kstr, split_str_test, .init = kstr_redirect_all_stdout)
{
    string stri = "Je\nsuis\nbenjamin\n";
    string want[]  = {"Je", "suis", "benjamin", NULL};
    text get = split_str(stri, '\n');

    for (int i = 0; i < length_text(want); i++)
        cr_assert_str_eq(get[i], want[i], "The result was [%s]. Expected [%s]\n", stri[i], want[i]);
}

Test(kstr, split_sstr_test, .init = kstr_redirect_all_stdout)
{
    string stri = "Je \nsuis \nbenjamin \n";
    string want[]  = {"Je", "suis", "benjamin", NULL};
    text get = split_sstr(stri, " \n");

    for (int i = 0; i < length_text(want); i++)
        cr_assert_str_eq(get[i], want[i], "The result was [%s]. Expected [%s]\n", stri[i], want[i]);
}

Test(kstr, add_str_text_test, .init = kstr_redirect_all_stdout)
{
    string stri = "Je\nsuis\nbenjamin\n";
    text get = split_str(stri, '\n');
    string want[]  = {"Je", "suis", "benjamin", "yo", NULL};

    add_str_text(&get, length_text(get), "yo");
    for (int i = 0; i < length_text(want); i++)
        cr_assert_str_eq(get[i], want[i], "The result was [%s]. Expected [%s]\n", stri[i], want[i]);
}