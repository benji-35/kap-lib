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

// =================================  TEST STR  =================================//

// ========================= TEST LENGTH ========================= //
Test(kstr, length_str_normal, .init = kstr_redirect_all_stdout)
{
    int size = length("Je suis une string de X caracteres");
    int want = 34;

    cr_assert_eq(want, size, "The result was [%d]. Expected [%d]\n", size, want);
}

Test(kstr, length_str_null, .init = kstr_redirect_all_stdout)
{
    int size = length(NULL);
    int want = 0;

    cr_assert_eq(want, size, "The result was [%d]. Expected [%d]\n", size, want);
}

// ========================= TEST COPY STR ========================= //

Test(kstr, copy_str_test_normal, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("Yo !");
    string want = "Yo !";

    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, copy_str_test_null, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str(NULL);
    string want = "";

    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

// ========================= TEST ADD CHAR STR ========================= //

Test(kstr, add_char_str_test, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("Je suis ben");
    string want = "Je suis ben.";

    add_char_str(&stri, '.');
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, add_char_strp_test, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("e suis ben.");
    string want = "Je suis ben.";

    add_char_strp(&stri, 'J', 0);
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

// ========================= TEST EMPTY STR ========================= //

Test(kstr, empty_str_test, .init = kstr_redirect_all_stdout)
{
    string stri = empty_str();
    string want = "\0";

    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, empty_str_size_test, .init = kstr_redirect_all_stdout)
{
    string stri = empty_str_size(1);
    string want = " ";

    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

// ========================= TEST REMOVE CHAR ========================= //

Test(kstr, rm_char_str_test, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("JJe");
    string want  = "Je";

    remove_char_str(&stri, 0);
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

// ========================= TEST SPLIT STR ========================= //

Test(kstr, split_str_test, .init = kstr_redirect_all_stdout)
{
    string stri = "Je\nsuis\nbenjamin\n";
    string want[]  = {"Je", "suis", "benjamin", NULL};
    text get = split_str(stri, '\n');

    for (int i = 0; i < length_text(want); i++)
        cr_assert_str_eq(get[i], want[i], "The result was [%s]. Expected [%s]\n", stri[i], want[i]);
    free_text(get);
}

Test(kstr, split_sstr_test, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("Je \nsuis \nbenjamin \n");
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
    free_text(get);
}

// ========================= TEST STAR WITH ========================= //

Test(kstr, start_with_test_one, .init = kstr_redirect_all_stdout)
{
    string stri = "Je suis un dev\n";
    int want = 1;
    int res = strat_with(stri, "Je");

    cr_assert_eq(want, res, "The result was [%d]. Expected [%d]\n", res, want);

}

Test(kstr, start_with_test_two, .init = kstr_redirect_all_stdout)
{
    string stri = "Je suis un dev\n";
    int want = 1;
    int res = strat_with(stri, "Je suis un");

    cr_assert_eq(want, res, "The result was [%d]. Expected [%d]\n", res, want);

}

Test(kstr, start_with_test_three, .init = kstr_redirect_all_stdout)
{
    string stri = "Je suis un dev\n";
    int want = 1;
    int res = strat_with(stri, "Je suis un dev\n");

    cr_assert_eq(want, res, "The result was [%d]. Expected [%d]\n", res, want);

}

Test(kstr, start_with_test_four, .init = kstr_redirect_all_stdout)
{
    string stri = "Je suis un dev\n";
    int want = 0;
    int res = strat_with(stri, "Je  suis une dev");

    cr_assert_eq(want, res, "The result was [%d]. Expected [%d]\n", res, want);

}

// ========================= TEST FINISH WITH ========================= //

Test(kstr, finish_with_test_one, .init = kstr_redirect_all_stdout)
{
    string stri = "Je suis un dev\n";
    int want = 1;
    int res = finish_with(stri, "\n");

    cr_assert_eq(want, res, "The result was [%d]. Expected [%d]\n", res, want);

}

Test(kstr, finish_with_test_two, .init = kstr_redirect_all_stdout)
{
    string stri = "Je suis un dev\n";
    int want = 1;
    int res = finish_with(stri, "Je suis un dev\n");

    cr_assert_eq(want, res, "The result was [%d]. Expected [%d]\n", res, want);

}

Test(kstr, finish_with_test_three, .init = kstr_redirect_all_stdout)
{
    string stri = "Je suis un dev\n";
    int want = 0;
    int res = finish_with(stri, "dev");

    cr_assert_eq(want, res, "The result was [%d]. Expected [%d]\n", res, want);

}