##
## EPITECH PROJECT, 2021
## C-Lib
## File description:
## start_tests
##

clear
make fclean -C tests/
make -C tests/
clear
tests/tests
make fclean -C tests/
tests/main-parser
rm -f tests/main-parser