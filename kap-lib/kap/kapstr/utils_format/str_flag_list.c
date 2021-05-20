/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** str_flag_list
*/

#include <kap/kstr.h>
#include <kapformats/kap_str_n.h>

sflag_t strflags[] = {
    {"s", &add_strstr},
    {"d", &add_intstr},
    {"b", &add_binstr},
    {"B", &add_binfstr},
    {"x", &add_hexstr},
    {"X", &add_hexfstr},
    {"p", &add_hexfstr},
    {"c", &add_charstr},
    {"i", &add_intstr},
    {"f", &add_doublestr},
    {"e", &add_doublestr},
    {"E", &add_doublestr},
    {"g", &add_doublestr},
    {"G", &add_doublestr}
};