/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kaprintf_listing_flag
*/

#include <kaprintf_n.h>

pflag_t pflags[] = {
    {"s", &my_putstr},
    {"d", &display_int},
    {"b", &display_binary},
    {"x", &display_hexa},
    {"X", &display_hexa},
    {"p", &display_pointer},
    {"c", &display_char},
    {"i", &display_int},
    {"f", &display_double},
    {"e", &display_double},
    {"E", &display_double},
    {"g", &display_double},
    {"G", &display_double},
    {"u", &display_unisgned_int},
    {"ll", &display_longlong},
    {"ull", &display_ulonglong},
    {"l", &display_long},
    {"ul", &display_ulong}
};