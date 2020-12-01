## 39. Find HCF and LCM of a given numbers

#! /bin/bash

read -p "Enter 2 number seperated by space: " n1 n2

#finding the highest value
if [[ $n1 -eq $n2 ]];then
   echo -e "H.C.F = \e[1;34m$n1\e[0m"
   echo -e "L.C.M = \e[1;34m$n1\e[0m"
   exit 0
elif [[ $n1 -gt $n2 ]];then
   greater=$n1
   lower=$n2
else
   greater=$n2
   lower=$n1
fi

# Copying Lower and Higher for finding LCM
lowerNum=$lower
greaterNum=$greater

#finding hcf
while [ $lower -ne 0 ];do
    hcf=$lower
    lower=$((greater%lower))
    greater=$hcf
done

echo -e "H.C.F = \e[1;34m$hcf\e[0m"

# # Finding LCM
lcm=$greaterNum
while [ $((lcm % lowerNum)) -ne 0 ]; do
    ((lcm+=greaterNum))
done
echo -e "L.C.M = \e[1;34m$lcm\e[0m"
