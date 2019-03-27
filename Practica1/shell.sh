#!/bin/bash
# -*- ENCODING: UTF-8 -*-
gcc -Wall main.c metodos.c tiempo.c
./a.out 100 5 < numeros10millones.txt >> shell.txt
./a.out 1000 5 < numeros10millones.txt >> shell.txt
./a.out 5000 5 < numeros10millones.txt >> shell.txt
./a.out 10000 5 < numeros10millones.txt >> shell.txt
./a.out 50000 5 < numeros10millones.txt >> shell.txt
./a.out 100000 5 < numeros10millones.txt >> shell.txt
./a.out 200000 5 < numeros10millones.txt >> shell.txt
./a.out 400000 5 < numeros10millones.txt >> shell.txt
./a.out 600000 5 < numeros10millones.txt >> shell.txt
./a.out 800000 5 < numeros10millones.txt >> shell.txt
./a.out 1000000 5 < numeros10millones.txt >> shell.txt
./a.out 2000000 5 < numeros10millones.txt >> shell.txt
./a.out 3000000 5 < numeros10millones.txt >> shell.txt
./a.out 4000000 5 < numeros10millones.txt >> shell.txt
./a.out 5000000 5 < numeros10millones.txt >> shell.txt
./a.out 6000000 5 < numeros10millones.txt >> shell.txt
./a.out 7000000 5 < numeros10millones.txt >> shell.txt
./a.out 8000000 5 < numeros10millones.txt >> shell.txt
./a.out 9000000 5 < numeros10millones.txt >> shell.txt
./a.out 10000000 5 < numeros10millones.txt >> shell.txt
exit
