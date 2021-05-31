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

#ifdef __cpluplus
extern "C" {
#endif

/// fucntion that return if num can be divide by div
/// @param num > number to divide
/// @param div > number that divide num
/// @return true if num can be divide by div
extern bool kdiv_by(kssize_t num, kssize_t div);

/// function that return the power
/// @param num > number to power
/// @param power > power value
/// @return result of power
extern kdsize_t kpower(ksize_t num, ksize_t power);

/// function that return the square root
/// @param nb > number to execute the square root
/// @return result of square root
extern kdsize_t ksquare_root(kussize_t nb);

#ifdef __cpluplus
}
#endif

#endif /* !_KAP_MATH_H */
