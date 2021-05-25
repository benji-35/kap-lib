/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kmath
*/

#ifndef _KAP_MATH_H
#define _KAP_MATH_H

#include <kap/kutils.h>

#ifndef ABS
#define ABS(value)    (((value) < (0)) ? (value * -1) : (value))
#endif /*ABS*/

bool_t kdiv_by(kssize_t num, kssize_t div);
kdsize_t kpower(ksize_t num, ksize_t power);
kdsize_t ksquare_root(kussize_t nb);

#endif /* !_KAP_MATH_H */
