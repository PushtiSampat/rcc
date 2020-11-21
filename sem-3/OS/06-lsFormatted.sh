# 6. The script will receive the filename or filename
# with its full path, the script should obtain information
# about this file as given by "ls -l" and display it in proper format.

#! /bin/bash

echo "---------- Using stat----------"
stat -c "%n | %A | %h | %U | %G | %s | %.19y" *


printf "\n---------- Using ls -l ----------\n"

# Without Concatenation
# ls -l | cut -d ' ' -f 1,2,3,4,5,6,7,8,9 -s | awk '{print $9,$2,$3,$4,$5,$6,$7,$8,$1}'

# With Concatenation
ls -l | cut -d ' ' -f 1,2,3,4,5,6,7,8,9 -s | awk '{print $9" | "$1" | "$3" | "$4" | "$5" | "$6,$7" | "$8}'
