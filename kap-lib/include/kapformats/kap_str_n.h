#ifndef _KAPSTR_FORMAT_
#define _KAPSTR_FORMAT_

#include <stdarg.h>
#include <kap/kstr.h>

char *int_to_binary(long long nb, int flag, int minimize);
char *int_to_hex(long long nb, int flag);
void add_strstr(string *str, va_list *list, int spaces);
void add_binstr(string *str, va_list *list, int spaces);
void add_binfstr(string *str, va_list *list, int spaces);
void add_hexstr(string *str, va_list *list, int spaces);
void add_hexfstr(string *str, va_list *list, int spaces);
void add_doublestr(string *str, va_list *list, int spaces);
void add_intstr(string *str, va_list *list, int spaces);
void add_charstr(string *str, va_list *list, int spaces);

#ifndef SFLAG_LENGTH
#define SFLAG_LENGTH 14
#endif /*SFLAG_LENGTH*/

typedef struct flag_s {
    string flag;
    void (*display)(string *str, va_list *list, int spaces);
} str_flag_t;

typedef str_flag_t sflag_t;

extern sflag_t strflags[];

#endif /* !_KAPSTR_FORMAT_ */
