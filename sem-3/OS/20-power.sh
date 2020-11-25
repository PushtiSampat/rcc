# 20 Two numbers are entered through the keyboard,
# find the power, one number raised to another.

#! /bin/bash

read -p "Enter base and exponent seperated by space: " base exponent
echo "$base^$exponent" | bc
