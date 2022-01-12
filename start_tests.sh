##
## EPITECH PROJECT, 2021
## C-Lib
## File description:
## start_tests
##

clear

echo "Do you want clear warnings after compiling ?"
read needClear
echo "Do you want play main.c test file"
read playmain
echo "Do you want play tests"
read playtests

clear

make fclean -C tests/
make -C tests/

libFile=./kap-lib/libkap.a
libMainExe=./tests/main_parser

if [ -e "$libFile" ]
then
    if [ "$needClear" == "y" ]
    then
        clear
    elif [ "$needClear" == "Y" ]
    then
        clear
    elif [ "$needClear" == "yes" ]
    then
        clear
    elif [ "$needClear" == "YES" ]
    then
        clear
    fi

    if [ -e "tests/tests" ]
    then
        if [ "$playtests" == "y" ]
        then
            tests/tests
        elif [ "$playtests" == "Y" ]
        then
            tests/tests
        elif [ "$playtests" == "yes" ]
        then
            tests/tests
        elif [ "$playtests" == "YES" ]
        then
            tests/tests
        fi

        if [ -e "$libMainExe" ]
        then
            if [ "$playmain" == "y" ]
            then
                valgrind $libMainExe
                rm -f libMainExe
            elif [ "$playmain" == "Y" ]
            then
                valgrind $libMainExe
                rm -f libMainExe
            elif [ "$playmain" == "yes" ]
            then
                valgrind $libMainExe
                rm -f libMainExe
            elif [ "$playmain" == "YES" ]
            then
                valgrind $libMainExe
                rm -f libMainExe
            fi
        else
            echo "$libMainExe do not exists"
        fi
    else
        echo "test file not found"
    fi
    make fclean -C tests/
else
    echo "lib not compile"
fi
