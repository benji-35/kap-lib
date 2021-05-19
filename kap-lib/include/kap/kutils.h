/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kutils
*/

#ifndef _KAP_UTILS_H
#define _KAP_UTILS_H

#include <stdio.h>

void kfree(void *__ptr);

typedef enum bool_e bool_t;
typedef unsigned long kusize_t;
typedef unsigned long long kussize_t;
typedef long ksize_t;
typedef long long kssize_t;
typedef long double kdsize_t;

#define true 1
#define false 0

#define UNUSED __attribute__((unused))

enum bool_e {
    FALSE,
    TRUE
};

bool_t can_open_file(char *path);
char *kopen_file(char *path);
void kwrite_file(char *path, char *txt, bool_t append);
void kfree(void *__ptr);

#endif /* !_KAP_UTILS_H */
