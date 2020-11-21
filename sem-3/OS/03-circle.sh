# 3. The length and breadth of a rectangle and radius of a circle
# are entered through the keyboard,
# calculate the perimeter and area of rectangle and
# area and circumference of the circle

#! /bin/bash

echo "Enter Length of Rectangle"
read length

echo "Enter Breadth of Rectangle"
read breadth

# echo "Enter Radius Of circle"
# read radius

perimeter=$(printf "2*($len+$bre)" | bc)
echo "Perimeter:" $perimeter

# echo "$length * $breadth" | bc
# echo "Area:" $area
