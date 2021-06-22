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

/// function that return hexa value of number nb
/// @param nb > 
/// @param flag >
/// @return the hexa in string
extern string int_to_hex(int nb, bool flag);

/// function that return hexa value from binary
/// @param bin > string that contain binary
/// @param flag > set true if you want hexa flag before hexa value else set false
/// @param binHaveFlag > set true if binary string contain at begining the binary flag
/// @return the hexa in string
extern string bin_to_hex(string bin, bool flag, bool binHaveFlag);

/// function that return binary from hex
/// @param hex > string that contain hexa
/// @param flag > set true if you want flag before binary value else set false
/// @param hexHaveFlag > set true if hexa have flag else set false
/// @return the binary value
extern string hex_to_bin(string hex, bool flag, bool hexHaveFlag);

/// function that return number value from hex
/// @param hex > string that contain hexa
/// @param hexHaveFlag > set true if hexa have flag else set false
/// @return the value
extern int hex_to_int(string hex, bool hexHaveFlag);
#ifdef __cplusplus
}
#endif

#endif /* !_KAP_MATH_H */
