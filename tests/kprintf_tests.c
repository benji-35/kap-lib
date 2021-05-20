/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <kap/klib.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// =========================  TEST INT  =================================//

Test(kprintf_number, int_easy_one, .init = redirect_all_stdout)
{
    kprintf("%d", 18);
    string want = "18";

    cr_assert_stdout_eq_str(want, "The result expected is %s\n", want);
}

Test(kprintf_number, int_easy_two, .init = redirect_all_stdout)
{
    kprintf("Yo j'ai %d ans\n", 18);
    string want = "Yo j'ai 18 ans\n";

    cr_assert_stdout_eq_str(want, "The result expected is %s\n", want);
}

Test(kprintf_number, int_easy_three, .init = redirect_all_stdout)
{
    kprintf("Yo j'ai %d ans\n", 28420);
    string want = "Yo j'ai 28420 ans\n";

    cr_assert_stdout_eq_str(want, "The result expected is %s\n", want);
}

Test(kprintf_number, int_neg_one, .init = redirect_all_stdout)
{
    kprintf("%d", -18);
    string want = "-18";

    cr_assert_stdout_eq_str(want, "The result expected is %s\n", want);
}

Test(kprintf_number, int_neg_two, .init = redirect_all_stdout)
{
    kprintf("Yo j'ai %d ans\n", -18);
    string want = "Yo j'ai -18 ans\n";

    cr_assert_stdout_eq_str(want, "The result expected is %s\n", want);
}

Test(kprintf_number, int_neg_three, .init = redirect_all_stdout)
{
    kprintf("Yo j'ai %d ans\n", -2849414);
    string want = "Yo j'ai -2849414 ans\n";

    cr_assert_stdout_eq_str(want, "The result expected is %s\n", want);
}

// =========================  TEST CHAR  =================================//

Test(kprintf_char, char_easy_one, .init = redirect_all_stdout)
{
    kprintf("%c", 'I');
    string want = "I";

    cr_assert_stdout_eq_str(want, "The result expected is %s\n", want);
}

// =========================  TEST STR  =================================//

Test(kprintf_str, str_easy_one, .init = redirect_all_stdout)
{
    kprintf("%s", "Benjamin");
    string want = "Benjamin";

    cr_assert_stdout_eq_str(want, "The result expected is %s\n", want);
}

Test(kprintf_str, str_easy_two, .init = redirect_all_stdout)
{
    kprintf("Creator of this lib is %s and he has 18.", "Benjamin");
    string want = "Creator of this lib is Benjamin and he has 18.";

    cr_assert_stdout_eq_str(want, "The result expected is %s\n", want);
}

// =========================  TEST BINARY  =================================//

// =========================  TEST HEXA  =================================//

// =========================  TEST POINTER  =================================//

// =========================  TEST DOUBLE  =================================//

// =========================  TEST UDOUBLE  =================================//

// =========================  TEST LONG LONG  =================================//

// =========================  TEST ULONG LONG  =================================//

// =========================  TEST LONG  =================================//

// =========================  TEST ULONG  =================================//
