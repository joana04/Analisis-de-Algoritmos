#!/bin/bash
# -*- ENCODING: UTF-8 -*-
gcc -Wall OrdenamientoShell.c

./a.out < numeros10millones.txt >> entrada.txt
exit
