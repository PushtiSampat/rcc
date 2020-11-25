# 26. Write a script for renaming each file in the directory 
# such that it will have the current shell PID as an extension.
# The shell script should ensure that the directories do not get renamed.

#! /bin/bash

# Why you shouldn't parse the output of ls
# http://mywiki.wooledge.org/ParsingLs

echo "This script is purposely exited to accidently avoid renaming files"
echo "To rename files comment the below line"
exit

for f in *; do
    [[ -e $f ]] || continue
    mv $f $f.$$
done
