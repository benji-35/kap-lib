/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kassert
*/

#include <kap/kutils.h>
#include <kap/kprintf.h>

void kassert_f(cstring __expr, cstring __fname, int __line,\
    void (*err)(cstring))
{
    kfprintf(kstderr, "Assertion : failed in {%s:%s} -> %s\n", __fname,\
    __line, __expr);
    if (err != KNULL)
        err = KNULL;
}