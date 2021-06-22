/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** hex_to_int
*/

#include <kap/kutils.h>
#include <kap/kmath.h>
#include <kap/kstr.h>

static int tot_from_hexch(char hex_ch)
{
    if (hex_ch >= 'A' && hex_ch <= 'F')
        return hex_ch - 65 + 10;
    if (hex_ch >= 'a' && hex_ch <= 'f')
        return hex_ch - 97 + 10;
    if (hex_ch >= '0' && hex_ch <= '9')
        return hex_ch - 48;
    return 0;
}

static string hex_to_bin_char(char hex_ch)
{
    string res = copy_str("0000");
    int tot = tot_from_hexch(hex_ch);

    if (tot >= 8) {
        tot -= 8;
        res[0] = '1';
    }
    if (tot >= 4) {
        tot -= 4;
        res[1] = '1';
    }
    if (tot >= 2) {
        tot -= 2;
        res[2] = '1';
    }
    if (tot >= 1) {
        tot--;
        res[3] = '1';
    }
    return res;
}

static void operator_hex_bin(ksize_t size, string *res, string hex)
{
    string hx_chr = NULL;

    for (ksize_t i = 0; i < size; i++) {
        hx_chr = hex_to_bin_char(hex[i]);
        if (i == 0) {
            str_rm_all_fochar(&hx_chr, '0');
        }
        concat_str_nm(res, hx_chr);
        kfree(hx_chr);
    }
}

string hex_to_bin(string hex, bool flag, bool hexHaveFlag)
{
    ksize_t size = length(hex);
    string res = NULL;
    string tamp = NULL;

    if (size == 0)
        return NULL;
    if (hexHaveFlag) {
        hex = hex + 2;
        size -= 2;
    }
    operator_hex_bin(size, &res, hex);
    if (flag) {
        tamp = concat_str_pos(res, "0b", 0);
        kfree(res);
        res = tamp;
    }
    return res;
}

int hex_to_int(string hex, bool hexHaveFlag)
{
    string bin = hex_to_bin(hex, false, hexHaveFlag);
    int res = bin_to_int(bin, false);

    kfree(bin);
    return res;
}