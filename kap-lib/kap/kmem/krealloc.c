/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** krealloc
*/

#include <stdlib.h>
#include <kap/kutils.h>

void *krealloc(void *__ptr, ksize_t __size, ksize_t __new_size)
{
    void *__nptr;

    if (!__size || !__new_size) {
        kfree(__ptr);
        return NULL;
    }
    kassert((__nptr = kcalloc(__new_size)) == NULL && "krealloc -> failed\n");
    if (!__nptr)
        return __ptr;
    kmemcpy(__nptr, __ptr, __size);
    kfree(__ptr);
    return __nptr;
}

void *krealloc_sec(void *__ptr, ksize_t __size, ksize_t __new_size)
{
    void *__nptr;

    if (!__size || !__new_size) {
        kfree(__ptr);
        return NULL;
    }
    kassert((__nptr = kcalloc_sec(__new_size)) == NULL && "krealloc ->\
    failed\n");
    if (!__nptr)
        return __ptr;
    kmemcpy(__nptr, __ptr, __size);
    kfree(__ptr);
    return __nptr;
}