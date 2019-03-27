#!/bin/bash
# -*- ENCODING: UTF-8 -*-
gcc -Wall main.c metodos.c tiempo.c
./a.out 100 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 1000 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 5000 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 10000 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 50000 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 100000 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 200000 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 400000 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 600000 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 800000 2 < numeros10millones.txt >> burbujaOptimizada.txt
./a.out 1000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
#./a.out 2000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
#./a.out 3000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
#./a.out 4000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
#./a.out 5000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
#./a.out 6000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
#./a.out 7000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
#./a.out 8000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
#./a.out 9000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
#./a.out 10000000 2 < numeros10millones.txt >> burbujaOptimizada.txt
exit
