#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette ./*.c ./*.h ./libft/*.c
echo -e "\033[32;1m"printfTester"\033[m"
read $a
git clone https://github.com/Tripouille/printfTester.git
cd printfTester
make a
cd ..
echo -e "\033[32;1m"ft_printf_tester"\033[m"
read $a
git clone https://github.com/paulo-santana/ft_printf_tester.git
cd ft_printf_tester
make
./tester
cd ..
make fclean
rm -rf printfTester ft_printf_tester
echo -e "\033[32;1m"DONE"\033[m"