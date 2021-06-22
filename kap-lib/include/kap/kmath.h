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

#ifdef __cplusplus
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

/// function that return the binary in string of number
/// @param nb > int var of number
/// @param flag > set true if you want binary flag before the binary number
/// @return a string of binary
extern string int_to_bin(int nb, bool flag);

/// function that return the value of binary
/// @param bin > string that contain binary
/// @param binHaveFlag > to exclude flag before operation
/// @return the value of binary in number
extern int bin_to_int(string bin, bool binHaveFlag);
#ifdef __cplusplus
}
#endif

#endif /* !_KAP_MATH_H */
