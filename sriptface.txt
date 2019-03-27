#!/bin/bash
# -*- ENCODING: UTF-8 -*-
gcc -Wall face.c 
./a.out < lazy_loading.txt >> out.txt
exit
