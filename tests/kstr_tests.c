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

// ========================= TEST PUT STR AND TEXT ========================= //
Test(kstr, display_str, .init = kstr_redirect_all_stdout)
{
    my_putstr("Hello World !");
    string want = "Hello World !";

    cr_assert_stdout_eq_str(want, "Expected [%s]\n", want);
}

Test(kstr, display_str_null, .init = kstr_redirect_all_stdout)
{
    my_putstr(NULL);
    string want = "NULL";

    cr_assert_stderr_eq_str(want, "Expected [%s]\n", want);
}

Test(kstr, display_str_fd, .init = kstr_redirect_all_stdout)
{
    my_putstr_fd("Hello World !", kstderr);
    string want = "Hello World !";

    cr_assert_stderr_eq_str(want, "Expected [%s]\n", want);
}

Test(kstr, display_str_fd_null, .init = kstr_redirect_all_stdout)
{
    my_putstr_fd(NULL, kstderr);
    string want = "NULL";

    cr_assert_stderr_eq_str(want, "Expected [%s]\n", want);
}

Test(kstr, display_text_fd, .init = kstr_redirect_all_stdout)
{
    char *txt[] = {"Hello", "World", "!", NULL};
    my_puttext(txt, kstdout);
    string want = "Hello\nWorld\n!\n";

    cr_assert_stdout_eq_str(want, "Expected [%s]\n", want);
}

Test(kstr, display_text_fd_null, .init = kstr_redirect_all_stdout)
{
    my_puttext(NULL, kstderr);
    string want = "NULL";

    cr_assert_stderr_eq_str(want, "Expected [%s]\n", want);
}

Test(kstr, display_char_fd, .init = kstr_redirect_all_stdout)
{
    kput_char('C', kstdout);
    string want = "C";

    cr_assert_stdout_eq_str(want, "Expected [%s]\n", want);
}

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

Test(kstr, rm_char_str_test_easy, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("JJe");
    string want  = "Je";

    remove_char_str(&stri, 0);
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_rm_fchar_test_easy, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("JCe");
    string want  = "Ce";

    str_rm_fchar(&stri);
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_rm_fchar_test_npossible, .init = kstr_redirect_all_stdout)
{
    string stri = NULL;
    string want  = NULL;

    str_rm_fchar(&stri);
    cr_assert_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_rm_pchar_test_easy, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("Yo toi comment ca va ?");
    string want = "Yo oi comment ca va ?";

    str_rm_pchar(&stri, 3);
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_rm_pchar_test_npossible, .init = kstr_redirect_all_stdout)
{
    string stri = NULL;
    string want = NULL;

    str_rm_pchar(&stri, 3);
    cr_assert_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
}

Test(kstr, str_rm_fochar_test_easy, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("Yo comment ca va toi ?");
    string want = "Yocomment ca va toi ?";

    str_rm_fochar(&stri, ' ');
    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_rm_fochar_test_npossible, .init = kstr_redirect_all_stdout)
{
    string stri = NULL;
    string want = NULL;

    str_rm_fochar(&stri, ' ');
    cr_assert_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_rm_occhar_test_easy, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("Yo comment ca va toi ?");
    string want = "Y cmment ca va ti ?";

    str_rm_occhar(&stri, 'o');
    cr_assert_str_eq(stri, want, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_rm_occhar_test_npossible, .init = kstr_redirect_all_stdout)
{
    string stri = NULL;
    string want = NULL;

    str_rm_fochar(&stri, ' ');
    cr_assert_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

// ========================= TEST SPLIT STR ========================= //

Test(kstr, split_str_test, .init = kstr_redirect_all_stdout)
{
    string stri = "Je\nsuis\nbenjamin\n";
    string want = "Je\nsuis\nbenjamin\n";
    text get = split_str(stri, '\n');

    my_puttext(get, kstdout);
    cr_assert_stdout_eq_str(want, "Expected [%s]\n", want);
    free_text(get);
}

Test(kstr, split_sstr_test, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("Je \nsuis \nbenjamin \n");
    string want  = "Je\nsuis\nbenjamin\n";
    text get = split_sstr(stri, " \n");

    my_puttext(get, kstdout);
    cr_assert_stdout_eq_str(want, "Expected [%s]\n", want);
    free_text(get);
}

Test(kstr, add_str_text_test, .init = kstr_redirect_all_stdout)
{
    string stri = "Je\nsuis\nbenjamin\n";
    text get = split_str(stri, '\n');
    string want = "Je\nsuis\nbenjamin\nyo\n";

    add_str_text(&get, length_text(get), "yo");
    my_puttext(get, kstdout);
    cr_assert_stdout_eq_str(want, "Expected [%s]\n", want);
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

// ========================= TEST STR CHAR OCCUR ========================= //

Test(kstr, str_char_occur_test_easy, .init = kstr_redirect_all_stdout)
{
    string stri = "canab, nop I can't. Just him cut the knife";
    int want = 3;
    int get = str_char_occur(stri, 'c');

    cr_assert_eq(want, get, "The result was [%d]. Expected [%d]\n", get, want);
}

Test(kstr, str_char_occur_test_easy_two, .init = kstr_redirect_all_stdout)
{
    string stri = "Canab, nop I can't. Just him cut the knife";
    int want = 2;
    int get = str_char_occur(stri, 'i');

    cr_assert_eq(want, get, "The result was [%d]. Expected [%d]\n", get, want);
}

Test(kstr, str_char_occur_test_no_char, .init = kstr_redirect_all_stdout)
{
    string stri = "Canab, nop I can't. Just him cut the knife";
    int want = 0;
    int get = str_char_occur(stri, 'y');

    cr_assert_eq(want, get, "The result was [%d]. Expected [%d]\n", get, want);
}

Test(kstr, str_char_occur_test_null, .init = kstr_redirect_all_stdout)
{
    string stri = NULL;
    int want = 0;
    int get = str_char_occur(stri, 'c');

    cr_assert_eq(want, get, "The result was [%d]. Expected [%d]\n", get, want);
}

// ========================= TEST STR LOWER CASE ========================= //

Test(kstr, str_to_lower_case_easy, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("YO JE SUis Le piraTE des ocEANS\n");
    string want = "yo je suis le pirate des oceans\n";

    str_to_lower_case(stri);
    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_to_lower_case_with_special_chars, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("YO JE SUis Le piraTE des ocEANS 123456789*-+\n");
    string want = "yo je suis le pirate des oceans 123456789*-+\n";

    str_to_lower_case(stri);
    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_to_lower_case_npossible, .init = kstr_redirect_all_stdout)
{
    string stri = NULL;
    string want = NULL;

    str_to_lower_case(stri);
    cr_assert_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

// ========================= TEST STR UPPER CASE ========================= //

Test(kstr, str_to_upper_case_easy, .init = kstr_redirect_all_stdout)
{
    string want = "YO JE SUIS LE PIRATE DES OCEANS\n";
    string stri = copy_str("yo je suis le pirate des oceans\n");

    str_to_upper_case(stri);
    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_to_upper_case_with_special_chars, .init = kstr_redirect_all_stdout)
{
    string want = "YO JE SUIS LE PIRATE DES OCEANS 123456789*-+\n";
    string stri = copy_str("yo je suis le pirate des oceans 123456789*-+\n");

    str_to_upper_case(stri);
    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, str_to_upper_case_npossible, .init = kstr_redirect_all_stdout)
{
    string stri = NULL;
    string want = NULL;

    str_to_upper_case(stri);
    cr_assert_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
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

// ========================= TEST STR EQUALITY ========================= //

Test(kstr, str_equality_easy, .init = kstr_redirect_all_stdout)
{
    bool_t get = str_equality("Hello World !", "Hello World !");
    bool_t want = true;

    cr_assert_eq(want, get, "The result was [%d]. Expected [%d]\n", get, want);
}

Test(kstr, str_equality_easy_two, .init = kstr_redirect_all_stdout)
{
    bool_t get = str_equality("hello World !", "Hello World !");
    bool_t want = false;

    cr_assert_eq(want, get, "The result was [%d]. Expected [%d]\n", get, want);
}

Test(kstr, str_equality_easy_three, .init = kstr_redirect_all_stdout)
{
    bool_t get = str_equality("Hello World !", NULL);
    bool_t want = false;

    cr_assert_eq(want, get, "The result was [%d]. Expected [%d]\n", get, want);
}

Test(kstr, str_equality_null, .init = kstr_redirect_all_stdout)
{
    bool_t get = str_equality(NULL, NULL);
    bool_t want = true;

    cr_assert_eq(want, get, "The result was [%d]. Expected [%d]\n", get, want);
}

// ========================= TEST CONCAT STR ========================= //

Test(kstr, concat_str_easy, .init = kstr_redirect_all_stdout)
{
    string want = "Hello World";
    string stri = concat_str("Hello", " World");

    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, concat_str_easy_two, .init = kstr_redirect_all_stdout)
{
    string want = "Hello World";
    string stri = concat_str("Hello World", NULL);

    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, concat_str_easy_three, .init = kstr_redirect_all_stdout)
{
    string want = "Hello World";
    string stri = concat_str(NULL, "Hello World");

    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, concat_str_null, .init = kstr_redirect_all_stdout)
{
    string want = NULL;
    string stri = concat_str(NULL, NULL);

    cr_assert_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

// ========================= TEST INT STR ========================= //

Test(kstr, int_to_str_one, .init = kstr_redirect_all_stdout)
{
    string want = "0";
    string stri = int_to_str(0);

    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, int_to_str_two, .init = kstr_redirect_all_stdout)
{
    string want = "23";
    string stri = int_to_str(23);

    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, int_to_str_three, .init = kstr_redirect_all_stdout)
{
    string want = "125698";
    string stri = int_to_str(125698);

    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, int_to_str_four, .init = kstr_redirect_all_stdout)
{
    string want = "-1";
    string stri = int_to_str(-1);

    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, int_to_str_five, .init = kstr_redirect_all_stdout)
{
    string want = "-1260";
    string stri = int_to_str(-1260);

    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

Test(kstr, int_to_str_six, .init = kstr_redirect_all_stdout)
{
    string want = "-125698";
    string stri = int_to_str(-125698);

    cr_assert_str_eq(want, stri, "The result was [%s]. Expected [%s]\n", stri, want);
    kfree(stri);
}

// ========================= TEST ADD TEXT TEXT ========================= //

Test(kstr, add_text_tex_one, .init = kstr_redirect_all_stdout)
{
    text get = split_str("Je\nsuis\ncool", '\n');
    text stri2 = split_str("comme\tdev\t!", '\t');
    string want = "Je\nsuis\ncool\ncomme\ndev\n!\n";

    add_text_text(&get, 3, stri2);
    my_puttext(get, kstdout);
    cr_assert_stdout_eq_str(want, "Expected [%s]\n", want);
    free_text(get);
}

// ========================= TEST ADVANCED SPLIT STR ========================= //

Test(kstr, advenced_split_str_one, .init = kstr_redirect_all_stdout)
{
    string stri = copy_str("yo ; je\n ; suis ; \nBenjamin\n");
    string want = "yo\nje\nsuis\nBenjamin\n";
    text get = advanced_split_str(stri, "%c%s", '\n', " ; ");

    my_puttext(get, kstdout);
    cr_assert_stdout_eq_str(want, "Expected [%s]\n", want);
    free_text(get);
}

// ========================= TEST STR FORMAT ========================= //

Test(kstr, str_format_one, .init = kstr_redirect_all_stdout)
{
    string stri = str_format("Hi my name's %s and I'm %d\n", "Benjamin", 19);
    string want = "Hi my name's Benjamin and I'm 19\n";

    cr_assert_str_eq(want, stri, "The result was [%d]. Expected [%d]\n", stri, want);
    kfree(stri);
}