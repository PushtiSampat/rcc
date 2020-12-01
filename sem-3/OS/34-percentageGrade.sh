# 34. Accept the marks of 5 subjects and calculate the percentage and grade.

#! /bin/bash

echo "Enter Marks of Subject 1"
read sub1

echo "Enter Marks of Subject 2"
read sub2

echo "Enter Marks of Subject 3"
read sub3

echo "Enter Marks of Subject 4"
read sub4

echo "Enter Marks of Subject 5"
read sub5

total=$(echo $sub1 + $sub2 + $sub3 + $sub4 + $sub5 | bc)
percentage=$(echo "scale=2; $total  / 5" | bc)
echo ""
echo "Percentage:" $percentage


if (( $(echo "$percentage > 90" | bc -l) ));then
    echo "Grade A"
elif (( $(echo "$percentage > 70" | bc -l) ));then
    echo "Grade B"
elif (( $(echo "$percentage > 50" | bc -l) ));then
    echo "Grade C"
elif (( $(echo "$percentage > 30" | bc -l) ));then
    echo "Grade D"
else
    echo "Fail"
fi
