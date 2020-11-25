# 15. Write a shell script to display the appropriate message like :
# Good Morning / Good Afternoon / Good Evening

#! /bin/bash

hour=`date +%H`
echo $hour


if [[ $hour -ge 5 && $hour  -lt 12 ]]; then
    echo "Good Morning"
elif [[ $hour -ge 12 && $hour  -lt 18 ]]; then
    echo "Good Afternoon"
else
    echo "Good Evening"
fi
