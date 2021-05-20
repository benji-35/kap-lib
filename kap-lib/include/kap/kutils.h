/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kutils
*/

#ifndef _KAP_UTILS_H
#define _KAP_UTILS_H

#include <stdio.h>

#ifndef _KAP_BOOL_
#define _KAP_BOOL_
typedef enum bool_e bool_t;
#define true 1
#define false 0
#endif /*_KAP_BOOL_*/

#ifndef _KAP_SIZE_
#define _KAP_SIZE_
typedef unsigned long kusize_t;
typedef unsigned long long kussize_t;
typedef long ksize_t;
typedef long long kssize_t;
typedef long double kdsize_t;
#endif /*_KAP_SIZE_*/

#ifndef _KAP_STR_TYPD_
#define _KAP_STR_TYPD_

typedef char** text;
typedef char* string;

#endif /*_KAP_STR_TYPD_*/

#define UNUSED __attribute__((unused))

enum bool_e {
    FALSE,
    TRUE
};

bool_t can_open_file(string path);
string kopen_file(string path);
void kwrite_file(string path, string txt, bool_t append);
void kfree(void *__ptr);

#endif /* !_KAP_UTILS_H */
