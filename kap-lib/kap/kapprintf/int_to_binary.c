/*
** EPITECH PROJECT, 2021
** myprintflib
** File description:
** int_to_binary
*/

int is_divisible_by(int nb, int div);
char *concat_str(char *str1, char *str2);
void putstr(char *str);
void add_char_in_str(char **str, char c);
char *empty_str(void);
void add_char_str_before(char **str, char c);
char *mall_str(char *str);
long long power_number(int nb, int power);

static int get_begin(long long nb, int minimize)
{
    long long res = 0;
    while (power_number(2, res) < nb)
        res += 1;
    if (minimize)
        return (res);
    while (is_divisible_by(res, 4) == 0)
        res++;
    return (res);
}

static void put_char_value_bin(long long *nb, int puiss, char **str)
{
    long long p = power_number(2, puiss);
    if (*nb < p) {
        add_char_in_str(str, '0');
    } else {
        *nb = *nb - p;
        add_char_in_str(str, '1');
    }
}

char *int_to_binary(long long nb, int flag, int minimize)
{
    char *str = empty_str();
    int puis = get_begin(nb, minimize);
    while (puis >= 0) {
        put_char_value_bin(&nb, puis, &str);
        puis--;
    }
    if (flag) {
        add_char_str_before(&str, 'x');
        add_char_str_before(&str, '0');
    }
    return (str);
}