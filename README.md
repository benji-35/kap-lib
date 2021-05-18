# C-Lib
My C-lib

# kprintf
kprintf is printf in kap lib.
flag list :
| N° | Flag |            description              |
|:--:|:----:|:-----------------------------------:|
| 00 |  %s  | display string |
| 01 |  %d / %i  | display integer |
| 02 |  %b  | display binary from integer value |
| 03 |  %x / %X  | display hexa from integer value |
| 04 |  %p  | display pointer adress |
| 05 |  %c  | display char |
| 06 |  %f / %e / %E / %g / %G  | display double |
| 07 |  %u  | display unsigned int |
| 08 |  %l  | display long |
| 09 |  %ul  | display unisgned long |
| 10 |  %ll  | display long long |
| 11 |  %ull  | display unsigned long long |

# kstr
#### FUNCTION LIST (ENGLISH VERSION)

| N° |     Name function     |      Arguments      |  Value return  |            description              |
|:--:|:---------------------:|:-------------------:|:--------------:|:-----------------------------------:|
|  1 |     add_char_str      |     string *str, char c|      void      | add a char at the end of string     |
|  2 |     add_char_strp     |     string *str, char c, int pos|      void      | add a char at specific position|
|  3 |    remove_char_str    |     string *str, int pos|      void      | remove a caracter at specific position|
|  4 |      add_str_text     |       text *txt, int pos, string str|      void      | insert the string in text at specific line.|
|  5 |     add_line_text     |       text *txt     |      void      | add a new empty line in text        |
|  6 |     add_line_ptext    |       text *txt, int pos|      void      | add new empty line at specific position in text|
|  7 |       nb_o_split      |       text *txt     |       int      | Return the number of \0 in text     |
|  8 |    is_alphanumeric    |        char c       |       int      | Return 1 if char is alphanumeric or 0 it's not an alphanurmeric char|
|  9 |       concat_str      |      string str1, string str2|     string     | Concat string 2 with string 1 and return the result|
| 10 |      str_contains     |      string str, string contain|       int      | Return 1 if str contain the content of contain otherwise it return 0|
| 11 |    str_contain_pos    |      string str, string contain|       int      | Return the position of the first string occurence. if there is no occurence then NULL is return|
| 12 |       copy_str        |      string str     |     string     | Return a copy of string             |
| 13 |      copy_str_fp      |      string str, int pos|     string     | Return a copy of string from a position|
| 14 |      copy_str_tp      |      string str, int pos|     string     | Return a copy of string from the begining to the position|
| 15 |     double_to_str     |       double f, int precision  |     string     | Return a double in string with precision number after coma|
| 16 |       empty_str       |         void        |     string     | Return an empty string with only \0 |
| 17 |     empty_str_size    |       int size      |     string     | Return an empty string with size  give in argument|
| 18 |      str_equality     |     string str1, string str2   |       int      | Return 1 if str1 and str2 are equals|
| 19 |       finish_with     |     string str1, string str2     |       int      | Return 1 if str1 finish with str2   |
| 20 |       free_text      |      text split     |      void      | Free the text                       |
| 21 |    insert_char_str    |      string *str, int position, char c |     void     | Add a char at the position in the string |
| 22 |      insert_str_s     |      string *str, string to_insert, int pos|      void      | Add a string at the position in the string str |
| 23 |       int_to_str      |        int nb       |     string     | Return int in string                |
| 24 |       reverse_str     |      string *str    |      void      | Reverse the string                  |
| 25 |        length         |      string str     |       int      | Return string size                  |
| 26 |      length_split     |      text split     |       int      | Return text size                    |
| 27 |     str_char_occur    |      string str, char c|       int      | Return number of occurence of char in string|
| 28 |      str_rm_occhar    |      string *str, char c    |      void      | Remove all occurence of char in string|
| 29 |      str_rm_fochar    |      string *str, char c|      void      | Remove the first accurence of char in string|
| 30 |      str_rm_pchar     |      string *str, int pos|      void      | Remove char at position pos in string |
| 31 |      str_rm_fchar     |      string *str    |      void      | Remove first char of string         |
| 32 |    remove_line_text   |       text *txt, int pos|      void      | Remove line in text at position     |
| 33 |remove_line_text_string|       text *txt, string str|      void      | Remove all lines with that contain string|
| 34 |  remove_all_ostr_text |       text txt, string str|      void      | Remove all same string in text      |
| 35 |    remove_ostr_str    |      string *str, string to_ren    |      void      | Remove all same string in string str|
| 36 |    replace_char_str   |      string str, char target, char replace|       void     | Replace all char equals to target in str to replace value|
| 37 |   replace_char_text   |       text txt, char target, char replace|      void      | Replace all char equals to target in text to replace value|
| 38 |       split_str       |      string str, char splitter|      text      | Split text for each splitter position in string and return the text splitted|
| 39 |      text_to_str      |      text split, string separator|     string     | From text, a string is generate and you can put a separator if you want (separator is nullable)|
| 40 |       strat_with      |      string str1, string str2|       int      | Return 1 if str1 start with str2 else function return 0|
| 41 |       get_words       |       string str    |      text      | Return a list with words of string  |
| 42 |    str_to_double      |       string str    |     double     | Return double value from double in string|
| 43 |      str_to_int       |       string str    |       int      | Return int value from int in string |
| 44 |   str_to_lower_case   |       string str    |      void      | Change all upper case to lower case |
| 45 |   str_to_upper_case   |       string str    |      void      | Change all lower case to upper case |
| 46 |   my_putstr   |       string str    |      void      | display string in output 1 (terminal) |
| 47 |   my_putstr_err   |       string str    |      void      | display string in output 2 (terminal) |
| 48 |   my_putstr_fd   |       string str, int fd    |      ssize_t      | display string in output fd and return result |
| 49 |   my_puttext   |  text txt, int fd  |      void      | display text in output fd |
| 50 |   split_sstr   | string str, string splitter |      text      | split string at each occurence of the string splitter in str |

#### FUNCTION LIST (VERSION FRANÇAISE)

| N° |     Name function     |      Arguments      |  Value return  |            description              |
|:--:|:---------------------:|:-------------------:|:--------------:|:-----------------------------------:|
|  1 |     add_char_str      |     string *str, char c|      void      | Ajoute un char à la fin de la string |
|  2 |     add_char_strp     |     string *str, char c, int pos|      void      | Ajoute un char à une position précise dans la string|
|  3 |    remove_char_str    |     string *str, int pos|      void      | Supprime un char à une position spécifique|
|  4 |      add_str_text     |       text *txt, int pos, string str|      void      | Insert une string dans le texte à une ligne spécifique|
|  5 |     add_line_text     |       text *txt     |      void      | Ajoute une ligne vide à la fin du texte|
|  6 |     add_line_ptext    |       text *txt, int pos|      void      | Ajoute une ligne vide à une ligne spécifique du texte|
|  7 |       nb_o_split      |       text *txt     |       int      | Retourne le nombre de \0 dans le texte|
|  8 |    is_alphanumeric    |        char c       |       int      | Retourne 1 si le char est un caractère alphanumérique sinon la fonction retourne 0|
|  9 |       concat_str      |      string str1, string str2|     string     | Ajoute la string str2 à la fin de la string str1 et retourne le résultat|
| 10 |      str_contains     |      string str, string contain|       int      | Retourne 1 si la string str contient la string contain|
| 11 |    str_contain_pos    |      string str, string contain|       int      | retroune la position de la première occurence de contain dans la string str. Si aucune occurence n'est trouvé alors la fonction retourne -1|
| 12 |       copy_str        |      string str     |     string     | Retourne la copie de la string str|
| 13 |      copy_str_fp      |      string str, int pos|     string     | Retourne la copie de la string str depuis la position pos|
| 14 |      copy_str_tp      |      string str, int pos|     string     | Retourne la copie de la string str jusqu'à la position pos|
| 15 |     double_to_str     |       double f, int precision  |     string     | Retourne la valeur de la double en string avec precision (int) chiffre après la virgule|
| 16 |       empty_str       |         void        |     string     | Retourne une string vide ayant la taille 0|
| 17 |     empty_str_size    |       int size      |     string     | Retourne une string vide ayant la taille demandé|
| 18 |      str_equality     |     string str1, string str2   |       int      | Retourne 1 si la string 1 est égale à la string 2 sinon la fonction retourne 0|
| 19 |       finish_with     |     string str1, string str2     |       int      | Retourne 1 si la string 1 finit avec la string 2 sinon la fonction retourne 0|
| 20 |       free_text      |      text split     |      void      | Free le text|
| 21 |    insert_char_str    |      string *str, int position, char c |     void     | Ajoute un char à une position dans la string|
| 22 |      insert_str_s     |      string *str, string to_insert, int pos|      void      | Insert une string dans une string à une position précise|
| 23 |       int_to_str      |        int nb       |     string     | Retourne un nombre entier en string|
| 24 |       reverse_str     |      string *str    |      void      | Inverse une string|
| 25 |        length         |      string str     |       int      | Retourne la taille de la string|
| 26 |      length_split     |      text split     |       int      | Retourne la taille du texte|
| 27 |     str_char_occur    |      string str, char c|       int      | Retourne le nombre d'occurences d'un char dans une string|
| 28 |      str_rm_occhar    |      string *str, char c    |      void      | Supprime toutes les occurences du char dans une string|
| 29 |      str_rm_fochar    |      string *str, char c|      void      | Supprime la première occurence du char dans une string|
| 30 |      str_rm_pchar     |      string *str, int pos|      void      | Supprime le char à une position dans une string|
| 31 |      str_rm_fchar     |      string *str    |      void      | Supprime le premier char dans une string|
| 32 |    remove_line_text   |       text *txt, int pos|      void      | Supprime la string du texte à la ligne indiquée|
| 33 |remove_line_text_string|       text *txt, string str|      void      | Supprime toutes les lignes d'un texte qui continnent la string str|
| 34 |  remove_all_ostr_text |       text txt, string str|      void      | Supprime toutes les occurences de la string str dans le texte|
| 35 |    remove_ostr_str    |      string *str, string to_ren    |      void      | Supprime toutes les occurences de la string to_ren dans la string str|
| 36 |    replace_char_str   |      string str, char target, char replace|       void     | Remplace toute les chars ayant la valeur target par la valeur replace dans la string str|
| 37 |   replace_char_text   |       text txt, char target, char replace|      void      | Remplace toute les chars ayant la valeur target par la valeur replace dans le texte txt|
| 38 |       split_str       |      string str, char splitter|      text      | Divise la string par rapport aux occurences de splitter dans la string str et en retourne un texte|
| 39 |      text_to_str      |      text split, string separator|     string     | Depuis un texte créer un string dans laquelle entre chaque ligne on peut rajouter une string|
| 40 |       strat_with      |      string str1, string str2|       int      | Retroune 1 si la string 1 commence par la string 2|
| 41 |       get_words       |       string str    |      text      | retourne la liste des mots dans la string str|
| 42 |    str_to_double      |       string str    |     double     | Passe une valeur double en string à une double|
| 43 |      str_to_int       |       string str    |       int      | Passe une valeur int en string à un int|
| 44 |   str_to_lower_case   |       string str    |      void      | Change toutes les majuscules en minuscules|
| 45 |   str_to_upper_case   |       string str    |      void      | Change toutes les minuscules en majuscules|
| 46 |   my_putstr   |       string str    |      void      | affiche la string dans la sortie 1 (terminal) |
| 47 |   my_putstr_err   |       string str    |      void      | affiche la string dans la sortie 2 (terminal) |
| 48 |   my_putstr_fd   |       string str, int fd    |      ssize_t      | affiche la string dans la sortie fd et retourne son résultat |
| 49 |   my_puttext   |  text txt, int fd  |      void      | affiche un texte dans la sortie fd |
| 50 |   split_sstr   | string str, string splitter |      text      | Découpe la string à chaque apparition de la string splitter |

# kmath

| N° |     Name function     |      Arguments      |  Value return  |            description              |
|:--:|:---------------------:|:-------------------:|:--------------:|:-----------------------------------:|
| 01 |   kdiv_by   | kssize_t num, kssize_t div | bool_t | return true if num can be divide by div |
| 02 |   kpower   | ksize_t num, ksize_t power | kdsize_t | return result of num power "power" |
| 03 |   ksquare_root   | kussize_t nb | kussize_t | return value of square root of nb |
| 04 |   kroot   | kusize_t nb, kusize_t rt | kussize_t | return value of rt root of nb |

# kutils