/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** int_to_hex
*/

#include <stdlib.h>
char *concat_str(char *str1, char *str2);
void add_char_str_before(char **str, char c);
void add_char_in_str(char **str, char c);
char *int_to_binary(unsigned int nb, int flag, int minimize);
char **split_str_from_end_number(char *str, int nb);
void free_splitted(char **splitted);
char *mall_str_from_size(int size);
int length(char *str);

static char *tab_hex(void)
{
    char *tab = concat_str("0123456789abcdef", NULL);
    return (tab);
}

static int size_hex(char **splitted)
{
    int res = 0;
    for (int i = 0; splitted[i] != NULL; i++)
        res++;
    return (res);
}

static char val_hex(char *str)
{
    int res = 0;
    char *tab = tab_hex();
    char result = ' ';
    if (str[0] == '1')
        res += 8;
    if (str[1] == '1')
        res += 4;
    if (str[2] == '1')
        res += 2;
    if (str[3] == '1')
        res += 1;
    result = tab[res];
    free(tab);
    return (result);
}

char *int_to_hex(long long nb, int flag)
{
    char *binary = int_to_binary(nb, 0, 0);
    char **splitted = split_str_from_end_number(binary, 4);
    int size = size_hex(splitted);
    char *hex = mall_str_from_size(size);
    for (int i = 0; i < size; i++)
        hex[i] = val_hex(splitted[i]);
    hex[size] = 0;
    free_splitted(splitted);
    free(binary);
    if (flag) {
        add_char_str_before(&hex, 'x');
        add_char_str_before(&hex, '0');
    }
    return (hex);
}