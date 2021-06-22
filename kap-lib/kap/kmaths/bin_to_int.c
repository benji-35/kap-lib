/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** bin_to_int
*/

#include <kap/kutils.h>
#include <kap/kmath.h>
#include <kap/kstr.h>

int bin_to_int(string bin, bool binHaveFlag)
{
    int res = 0;
    ksize_t len = length(bin) - 1;
    ksize_t id = 0;

    if (bin == NULL)
        return 0;
    if (binHaveFlag) {
        bin = bin + 2;
        len -= 2;
    }
    while (len >= 0) {
        if (bin[id] == '1') {
            res += kpower(2, len);
        }
        len--;
        id++;
    }
    return res;
}