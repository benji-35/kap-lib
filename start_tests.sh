##
## EPITECH PROJECT, 2021
## C-Lib
## File description:
## start_tests
##

clear
make fclean -C tests/
make -C tests/
libFile=./kap-lib/libkap.a

libMainExe=./tests/main_parser

if [ -e "$libFile" ]; then
    clear
    tests/tests
    if [ -e "$libMainExe" ]; then
        valgrind $libMainExe
        rm -f libMainExe
    else
        echo "$libMainExe do not exists"
    fi
    make fclean -C tests/
else
    echo "lib not compile"
fi
