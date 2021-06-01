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

#ifdef __cplusplus
extern "C" {
#endif

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

///kmemset will set pointer value
///@param __ptr > pointer to set value
///@param __val > value to set
///@param __size > size of the pointer
extern void kmemset(void *__ptr, int __val, ksize_t __size);

///kmemcpy copy valu of pointer __src to pointer __ptr
///@param __ptr > pointer that get value copied
///@param __src > pointer with value to copy
///@param __size > size of __src pointer
///@return void * > return __ptr after copied (argument __ptr will update)
extern void *kmemcpy(void *__ptr, void *__src, ksize_t __size);

///same as free of stdlib BUT if pointer is NULL, the function do nothing
///@param __ptr > pointer to free
extern void kfree(void *__ptr);

///same as malloc or kmalloc BUT set your pointer to 0
///@param __size > size of malloc
///@return void * > return result of malloc
extern void *kcalloc(ksize_t __size);

///same as kcalloc BUT if kcalloc do not work, programm exit with value 84
///@param __size > size of malloc
///@return void * > return result of malloc
extern void *kcalloc_sec(ksize_t __size);

///krealloc realloc memory for a specific pointer with a new size
///@param __ptr > pointer to realloc
///@param __size > current size of pointer
///@param __new_size > new size of malloc
///@return void * > return result of remalloc
extern void *krealloc(void *__ptr, ksize_t __size, ksize_t __new_size);

///kmalloc_sec is same as krealloc but if realloc do not work, programm exit with value 84
///@param __ptr > pointer to realloc
///@param __size > current size of pointer
///@param __new_size > new size of malloc
///@return void * > return result of remalloc
extern void *krealloc_sec(void *__ptr, ksize_t __size, ksize_t __new_size);

///kmalloc return the malloc
///@param __size > size of malloc
///@return void * > return result of malloc
extern void *kmalloc(ksize_t __size);

///kmalloc_sec return the malloc BUT if malloc return NULL, programm is exit 84
///@param __size > size of malloc
///@return void * > return result of malloc
extern void *kmalloc_sec(ksize_t __size);

#ifdef __cplusplus
}
#endif

#endif /* !_KAP_MEM_H_ */
