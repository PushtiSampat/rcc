# 37. Display all the numbers from 1 to 100 which are divisible by 7.

#! /bin/bash

checkDivisible(){
    n=$1
    if [ $((n % 7)) -eq 0 ]; then
        return 1
    fi
    return 0

}

num=1

while [ $num -le 100 ]
do
    checkDivisible $num
    isDivisible=$?

    if [ $isDivisible -eq 1 ]
    then
        printf "$num "
    fi

    num=$((num+1))
done
