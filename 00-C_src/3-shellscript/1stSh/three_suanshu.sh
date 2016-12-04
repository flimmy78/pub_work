#!/bin/bash

a=10
b=20
echo "a = ${a},b = ${b}"

val=`expr $a + $b`
echo "a + b :$val"
