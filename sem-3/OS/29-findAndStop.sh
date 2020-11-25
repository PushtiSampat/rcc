# 29. The word "unix" is present in only some of the files
# supplied as arguments to the shell script.
# You script should search each of these files in turn and
# stop at the first file that it encounters containing the word unix. 
# The filename should be displayed on the screen.

#! /bin/bash

for i; do
    echo "Searching file: $i ..."

    # Add -q option when you don't need the string displayed when it was found.
    if grep -q "unix" "$i"; then
        echo "Found in $i"
        exit
    fi
    echo "Done."
done
