/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kassert
*/

#include <kap/kutils.h>
#include <kap/kprintf.h>
#include <stdlib.h>

bool kassert_f(bool isfail, cstring __expr, cstring __fname, int __line)
{
    if (!isfail)
        return (false);
    kfprintf(kstderr, "Assertion failed in [%s:%d] -> (%s)\n", \
    __fname, __line, __expr);
    return (true);
}

bool kassert_e(bool isfail, cstring __expr, cstring __fname, int __line)
{
    if (!isfail)
        return (false);
    kfprintf(kstderr, "Assertion failed in [%s:%d] -> (%s)\n", \
    __fname, __line, __expr);
    exit (84);
    return (true);
}