# 30. A shell script receives even number of filenames.
# Suppose four filenames are supplied then the first file should
# get copied into second file,
# the third file should get copied into fourth and so on.
# If odd number of filenames are supplied display error message.

#! /bin/bash

# Zero Arguments
if [ $# -eq 0 ]; then
    echo "No Arguments"
    exit
fi

# If even no of args
if [[ $(( $# % 2 )) == 0 ]]; then

    # Looping through each Argument
    count=1
    for i; do
        if !(($count % 2)); then
            cp $prevFile $i
            echo "'$prevFile' copied to -> $i"
        else
            prevFile=$i
        fi
        ((count++))
    done

# if odd no of args
else
    echo "Odd no of Arguments"
    exit
fi
