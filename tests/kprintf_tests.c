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
    cr_assert_stdout_eq_str("18");
}

Test(kprintf_number, int_easy_two, .init = redirect_all_stdout)
{
    kprintf("Yo j'ai %d ans\n", 18);
    cr_assert_stdout_eq_str("Yo j'ai 18 ans\n");
}

Test(kprintf_number, int_easy_three, .init = redirect_all_stdout)
{
    kprintf("Yo j'ai %d ans\n", 28420);
    cr_assert_stdout_eq_str("Yo j'ai 28420 ans\n");
}

Test(kprintf_number, int_neg_one, .init = redirect_all_stdout)
{
    kprintf("%d", -18);
    cr_assert_stdout_eq_str("-18");
}

Test(kprintf_number, int_neg_two, .init = redirect_all_stdout)
{
    kprintf("Yo j'ai %d ans\n", -18);
    cr_assert_stdout_eq_str("Yo j'ai -18 ans\n");
}

Test(kprintf_number, int_neg_three, .init = redirect_all_stdout)
{
    kprintf("Yo j'ai %d ans\n", -2849414);
    cr_assert_stdout_eq_str("Yo j'ai -2849414 ans\n");
}

// =========================  TEST CHAR  =================================//

// =========================  TEST STR  =================================//

// =========================  TEST BINARY  =================================//

// =========================  TEST HEXA  =================================//

// =========================  TEST POINTER  =================================//

// =========================  TEST DOUBLE  =================================//

// =========================  TEST UDOUBLE  =================================//

// =========================  TEST LONG LONG  =================================//

// =========================  TEST ULONG LONG  =================================//

// =========================  TEST LONG  =================================//

// =========================  TEST ULONG  =================================//
