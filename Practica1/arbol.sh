#!/bin/bash
# -*- ENCODING: UTF-8 -*-
gcc -Wall main.c metodos.c tiempo.c
./a.out 10000000 6 < numeros10millones.txt >> salida.txt
exit
