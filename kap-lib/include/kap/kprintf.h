/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kprintf
*/

#ifndef KPRINTF_H_
#define KPRINTF_H_

#include <kap/kutils.h>

#ifdef __cpluplus
extern "C" {
#endif

extern void kprintf(string __cmd, ...);
extern void kfprintf(int fd, string __cmd, ...);

#ifdef __cpluplus
}
#endif

#endif /* !KPRINTF_H_ */
