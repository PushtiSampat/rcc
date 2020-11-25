# 18. Find the factorial of any number.

#!/bin/bash

read -p "Enter a number: " num
fact=1
 
while [ $num -gt 1 ]
do
  fact=$((fact*num))
  num=$((num-1))
done
 
echo $fact 
