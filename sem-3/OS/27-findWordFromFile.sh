# 27. A file called wordfile consists of several words.
# Write a shell script which will receive a list of filenames,
# the first of which would be wordfile.
# The shell script should report all occurences of each word 
# in wordfile in the rest of the files supplied as arguments

#! /bin/bash

if [ $# -eq 0 ]; then
    printf "Usage:\n"
    echo "./27-findWordFromFile.sh <wordFile> <findFile ...>"
    exit
fi

filesToRead=$(($#-1))
echo $filesToRead

# Reading Line by Line
while read line; do

    # Reading Word by Word
    for word in $line; do
        echo "Searching word: '$word' ..."

        # 2 is slice starting index
        # filesToRead is slice length
        grep --color=always -n $word ${@:2:filesToRead}

        printf "Done.\n\n"
    done

done <"$1" # $1 is the file name we want to search


# GREP ----------------
# -n is for line number
# Use -o, and we can only print the fetched word, instead of line
