# 2. The distance between two cities is input through the keyboard.  (in km).
# Write a program to    convert this distance into
# metres, feet, inches and centimeters and display the results.

#!/bin/bash

echo "Enter Distance Between 2 cities (in km)"
read kms

kms=$(echo $kms*1.0 | bc -l);
metres=$(echo $kms*1000 | bc -l)
feet=$(echo $kms*3280.84 | bc -l);
inches=$(echo $kms*39370.1 | bc -l);
cms=$(echo $kms*100000 | bc -l);

echo "kms:" $kms
echo "metres:" $metres
echo "feet:" $feet
echo "inches:" $inches
echo "cms:" $cms
