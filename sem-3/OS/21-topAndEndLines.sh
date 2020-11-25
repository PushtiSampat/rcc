# 21. Write a script which has the functionality similar 
# to head and tail commands.

# This script takes
# First argument as number of lines to print
# Second argument as file name

#! /bin/bash
RED='\033[0;31m'
NC='\033[0m' # No Color

# Using Head Tail ===================================
echo -e "\e[1;36m"  # Changing Color
printf " ---------- Using Head and Tail ----------\n"
echo -en "\e[0m"  # Changing Color Back
head -$1 $2
echo " ..."
tail -$1 $2

lines=$(wc -l $2 | awk '{print $1;}')


# Using SED ===================================
startFromLine=$(echo "$lines-$1" | bc)
echo -e "\e[1;36m"  # Changing Color
printf "\n ---------- Using sed ----------\n"
echo -en "\e[0m"  # Changing Color Back
sed -n 1,$1p $2
echo " ..."
tail -$1 $2

# Count Lines
lines=$(wc -l $2 | awk '{print $1;}')


# Using Perl ===================================
# Incrementing by +1, because perl start to print from that lines
# So 1 line need to be reduced
let "startFromLine=startFromLine+1"
echo -e "\e[1;36m"  # Changing Color
printf "\n ---------- Using perl ----------\n"
echo -en "\e[0m"  # Changing Color Back
perl -ne"1..$1 and print" $2
echo " ..."
perl -ne"$startFromLine..$1 and print" $2
