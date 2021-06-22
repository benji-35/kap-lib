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

#ifdef __cplusplus
extern "C" {
#endif

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

#ifndef UNUSED
#define UNUSED __attribute__((unused))
#endif /*UNUSED*/

/// check if file can be open or not
/// @param path > path of file
/// @return true if file can be open or false if file can't be open
extern bool can_open_file(cstring path);

/// open file and return content
/// @param path > path of file
/// @return content. If file can't be open return NULL
extern string kopen_file(cstring path);

/// open file and return content
/// @param path > path of file
/// @return content as text format. If file can't be open return NULL
extern text kopen_file_t(cstring path);

/// write in file
/// @param path > path of file
/// @param str > string that will write in file
/// @param append > if true : the str will write after file content. If false : the file will clear and then write str
extern void kwrite_file(string path, string str, bool append);

/// check the extension of a file
/// @param path > path of file
/// @param __exten > extension want
/// @return true if file have the good extension. False if it doesn't
extern bool check_extension_file(string path, string __exten);

#ifdef __cplusplus
}
#endif

#endif /* !_KAP_UTILS_H */
