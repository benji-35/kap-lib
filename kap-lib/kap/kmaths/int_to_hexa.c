/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** int_to_hexa
*/

#include <kap/kutils.h>
#include <kap/kmath.h>
#include <kap/kstr.h>

static void reformat_bin_hex(string *bin)
{
    while (!kdiv_by(length(*bin), 4))
        add_char_strp(bin, '0', 0);
}

static char get_chhex_fromtot(int tot)
{
    if (tot < 10)
        return tot + 48;
    return tot + 65 - 10;
}

static string hex_from_bin(string bin)
{
    string res = NULL;
    ksize_t size = length(bin);
    int tot = 0;

    for (ksize_t i = 0; i < size; i += 4) {
        if (bin[i] == '1')
            tot += 8;
        if (bin[i + 1] == '1')
            tot += 4;
        if (bin[i + 2] == '1')
            tot += 2;
        if (bin[i + 3] == '1')
            tot += 1;
        add_char_str(&res, get_chhex_fromtot(tot));
        tot = 0;
    }
    return res;
}

string int_to_hex(int nb, bool flag)
{
    string bin = int_to_bin(nb, false);
    string res = NULL;
    string tamp = NULL;

    reformat_bin_hex(&bin);
    res = hex_from_bin(bin);
    kfree(bin);
    if (flag) {
        tamp = concat_str_pos(res, "0x", 0);
        kfree(res);
        res = tamp;
    }
    return res;
}

string bin_to_hex(string bin, bool flag, bool binHaveFlag)
{
    string _bin = copy_str(bin);
    string res = NULL;
    string tamp = NULL;

    if (binHaveFlag) {
        kfree(_bin);
        bin = bin + 2;
        _bin = copy_str(bin);
    }
    reformat_bin_hex(&_bin);
    res = hex_from_bin(_bin);
    kfree(_bin);
    if (flag) {
        tamp = concat_str_pos(res, "0x", 0);
        kfree(res);
        res = tamp;
    }
    return res;
}