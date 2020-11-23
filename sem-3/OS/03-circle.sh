# 3. The length and breadth of a rectangle and radius of a circle
# are entered through the keyboard,
# calculate the perimeter and area of rectangle and
# area and circumference of the circle

#! /bin/bash

# ----- Rectangle -----
echo "Enter Length of Rectangle"
read length

echo "Enter Breadth of Rectangle"
read breadth

perimeter=$(printf '2*(%s + %s)\n' "$length" "$breadth" | bc)
echo "Perimeter of Rectangle:" $perimeter

area=$(printf '%s * %s\n' "$length" "$breadth" | bc)
echo "Area of Rectangle:" $area


# ----- Circle -----
printf "\nEnter Radius Of circle\n"
read radius

cirArea=$(printf '3.14 * %s * %s\n' "$radius" "$radius" | bc)
echo "Area of Circle:" $cirArea

circumference=$(printf '2 * 3.14 * %s\n' "$radius" | bc)
echo "Area of Circle:" $circumference
