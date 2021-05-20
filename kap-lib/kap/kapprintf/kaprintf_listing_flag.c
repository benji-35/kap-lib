/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kaprintf_listing_flag
*/

#include <kapformats/kaprintf_n.h>

pflag_t pflags[] = {
    {"ull", &display_ulonglong},
    {"ul", &display_ulong},
    {"ll", &display_longlong},
    {"s", &display_str},
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
    {"l", &display_long}
};