# 17. Create a menu driven calculator which asks for
# two integers and perform basic arithmetic operations.

#! /bin/bash

echo "Enter Number 1"
read a

echo "Enter Number 2"
read b

#! /bin/bash

echo "1) Add"
echo "2) Subtract"
echo "3) Multiply"
echo "4) Divide"
echo "5) Modulo Division"

read choice

case $choice in
    1)  echo $(($a + $b));;
    2)  echo $(($a - $b));;
    3)  echo $(($a * $b));;
    4)  echo $(($a / $b));;
    5)  echo $(($a % $b));;
    *)  echo "Invalid Option"
esac
