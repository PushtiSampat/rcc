# 38. Find the largest and smallest of 3 different numbers.

#! /bin/bash

read -p "Enter 3 numbers seperated by space: " n1 n2 n3

if [[ $n1 > $n2 && $n1 > $n3 ]]; then
    echo "$n1"
elif [[ $n2 > $n1 && $n2 > $n3 ]]; then
    echo "$n2"
elif [[ $n3 > $n2 && $n3 > $n1 ]]; then
    echo "$n3"
elif [[ $n3 == $n2 || $n1 == $n2 || $n1 == $n3 ]]; then
    echo "Two or more numbers are same"
fi
