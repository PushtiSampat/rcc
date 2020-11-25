# 25. Program must display all the combinations of 1, 2, and 3.

#! /bin/bash

for i in 1 2 3
do
    for j in 1 2 3
    do
        for k in 1 2 3
        do
            if [[ $k -le $j && $j -le $i ]]; then
                echo $i $j $k
            fi
        done
    done
done
