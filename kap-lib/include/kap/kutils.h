/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kutils
*/

#ifndef _KAP_UTILS_H
#define _KAP_UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <kap/kmem.h>
#include <kap/kasserts.h>

#ifndef _KAP_SIZE_
#define _KAP_SIZE_

typedef unsigned long kusize_t;
typedef unsigned long long kussize_t;
typedef long ksize_t;
typedef long long kssize_t;
typedef long double kdsize_t;
typedef unsigned char uchar_t;
typedef uchar_t uint8_t;

#endif /*_KAP_SIZE_*/

#ifndef _KAP_STR_TYPD_
#define _KAP_STR_TYPD_

typedef char ** text;
typedef char * string;
typedef char const * cstring;
typedef char const ** ctext;

#endif /*_KAP_STR_TYPD_*/

#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif

#ifndef KNULL
#define KNULL ((void *)0)
#endif /*KNULL*/

#ifndef OBJECT
#define OBJECT void *
#endif

#ifndef _KAP_FD_
#define _KAP_FD_

#define kstdin 0
#define kstdout 1
#define kstderr 2

#endif /*_KAP_FD_*/

#ifndef _KAP_UNUSED_
#define _KAP_UNUSED_

#define UNUSED __attribute__((unused))

#endif /*_KAP_UNUSED_*/

bool can_open_file(string path);
string kopen_file(string path);
text kopen_file_t(string path);
void kwrite_file(string path, string txt, bool append);
void kfree(void *__ptr);
bool check_extension_file(string path, string __exten);

#endif /* !_KAP_UTILS_H */
