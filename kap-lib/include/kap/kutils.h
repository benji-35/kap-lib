/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kutils
*/

#ifndef _KAP_UTILS_H
#define _KAP_UTILS_H

#include <kap/kstr.h>

void kfree(void *__ptr);

typedef enum bool_e bool_t;
typedef unsigned long kusize_t;
typedef unsigned long long kussize_t;
typedef long ksize_t;
typedef long long kssize_t;
typedef long double kdsize_t;

#define true 1
#define false 0

enum bool_e {
    FALSE,
    TRUE
};

bool_t can_open_file(string path);
string kopen_file(string path);
void kwrite_file(string path, string txt, bool_t append);
void kfree(void *__ptr);

#endif /* !_KAP_UTILS_H */
