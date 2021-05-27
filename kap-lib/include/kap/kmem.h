/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kmem
*/

#ifndef _KAP_MEM_H_
#define _KAP_MEM_H_

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void kmemset(void *__ptr, int __val, ksize_t __size);
void *kmemcpy(void *__ptr, void *__src, ksize_t __size);
void kfree(void *__ptr);
void *kcalloc(ksize_t __size);
void *krealloc(void *__ptr, ksize_t __size, ksize_t __new_size);

#endif /* !_KAP_MEM_H_ */
