#!/bin/bash
# -*- ENCODING: UTF-8 -*-
gcc -Wall main.c metodos.c tiempo.c
#./a.out 100 1 < numeros10millones.txt >> bs.txt
#./a.out 1000 1 < numeros10millones.txt >> bs.txt
#./a.out 5000 1 < numeros10millones.txt >> bs.txt
#./a.out 10000 1 < numeros10millones.txt >> bs.txt
./a.out 50000 1 < numeros10millones.txt >> bs.txt
./a.out 100000 1 < numeros10millones.txt >> bs.txt
./a.out 200000 1 < numeros10millones.txt >> bs.txt
./a.out 400000 1 < numeros10millones.txt >> bs.txt
./a.out 600000 1 < numeros10millones.txt >> bs.txt
./a.out 800000 1 < numeros10millones.txt >> bs.txt
./a.out 1000000 1 < numeros10millones.txt >> bs.txt
#./a.out 2000000 1 < numeros10millones.txt >> bs.txt
#./a.out 3000000 1 < numeros10millones.txt >> bs.txt
#./a.out 4000000 1 < numeros10millones.txt >> bs.txt
#./a.out 5000000 1 < numeros10millones.txt >> bs.txt
#./a.out 6000000 1 < numeros10millones.txt >> bs.txt
#./a.out 7000000 1 < numeros10millones.txt >> bs.txt
#./a.out 8000000 1 < numeros10millones.txt >> bs.txt
#./a.out 9000000 1 < numeros10millones.txt >> bs.txt
#./a.out 10000000 1 < numeros10millones.txt >> bs.txt
exit
