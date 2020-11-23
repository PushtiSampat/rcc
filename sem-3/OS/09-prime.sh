#! /bin/bash

checkPrime () {
    n=$1
    if [ $n -le 1 ]
    then
        return 0
    fi

    if [ $n -le 3 ]
    then
        return 1
    fi

    if [[ $(($n % 2)) -eq 0 || $(($n % 3)) -eq 0 ]]
    then
        return 0
    fi

    i=5
    while [ $(($i*$i)) -le $n ]
    do
        if [[ $(($n % $i)) -eq 0 || $(($n % ($i+2))) -eq 0 ]]
        then
            return 0
        fi
        i=$(($i+6))
    done

    return 1
}


echo "Enter num"
read num

checkPrime $num
isPrime=$?

if [ $isPrime -eq 1 ]
then
    echo "Prime"
else
    echo "Composite"
fi
