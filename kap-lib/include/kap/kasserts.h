/*
** EPITECH PROJECT, 2021
** C-Lib
** File description:
** kasserts
*/

#ifndef _KAP_ASSERTS_H_
#define _KAP_ASSERTS_H_

#include <stdbool.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef _KAP_STR_TYPD_
#define _KAP_STR_TYPD_

typedef char ** text;
typedef char * string;
typedef char const * cstring;
typedef char const ** ctext;

#endif /*_KAP_STR_TYPD_*/

#ifndef kASSERT_FUNCTION
#define kASSERT_FUNCTION NULL
#endif /*kASSERT_FUNCTION*/

#ifdef __cplusplus
extern "C" {
#endif

extern bool kassert_e(bool isfail, cstring __expr, cstring __fname, int __line);
extern bool kassert_f(bool isfail, cstring __expr, cstring __fname, int __line);

#define kassert(__expr) kassert_f(__expr, #__expr, __FILE__, __LINE__)
#define keassert(__expr) kassert_e(__expr, #__expr, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif /* !_KAP_ASSERTS_H_ */
