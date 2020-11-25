# 32. The script receives any number of filenames as arguments. 
# It should check whether every argument supplied is a file or directory.
# If it is a directory it should be reported.
# If it is a filename then name of the file as well as the
# number of lines present in it should be reported.

#! /bin/bash

for i; do
    if [[ -d $i ]]; then
        echo "$i -> directory"
    elif [[ -f $i ]]; then
        printf "$i -> file with lines: "
        wc -l $i | awk {'print $1'}
    else
        echo "$i -> Invalid"
    fi
done
