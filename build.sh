#!/bin/bash

code="$PWD"
opts=-c
cd build > /dev/null
c++ $opts $code/code\main.c -o raytracer
cd $code > /dev/null
