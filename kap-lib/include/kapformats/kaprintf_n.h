/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kaprintf_n
*/

#ifndef KAPRINTF_N_H_
#define KAPRINTF_N_H_

#include <stdarg.h>
#include <kap/kstr.h>

void display_str(va_list *data, int nb, int fd);
void display_binary(va_list *data, int nb, int fd);
void display_hexa(va_list *data, int nb, int fd);
void display_pointer(va_list *data, int nb, int fd);
void display_double(va_list *data, int bef, int fd);
void display_int(va_list *data, int bef, int fd);
void display_unisgned_int(va_list *data, int bef, int fd);
void display_short(va_list *data, int bef, int fd);
void display_unsigned_short(va_list *data, int bef, int fd);
void display_long(va_list *data, int bef, int fd);
void display_ulong(va_list *data, int bef, int fd);
void display_longlong(va_list *data, int bef, int fd);
void display_ulonglong(va_list *data, int bef, int fd);
char *int_to_binary(long long nb, int flag, int minimize);
char *int_to_hexa(long long nb, int flag);
void display_char(va_list *data, int nb, int fd);

#define FLAG_LENGTH 10

typedef struct flag_s {
    string flag;
    void (*display)(va_list *list, int spaces, int fd);
} print_flag_t;

typedef print_flag_t pflag_t;

extern pflag_t pflags[];

#endif /* !KAPRINTF_N_H_ */
