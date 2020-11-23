# 7. If cost price and selling price of an item are entered
# through the keyboard, write a program to determine whether
# the seller has made profit or loss. Also determine
# how much profit/loss is made.

#! /bin/bash

printf "Enter Cost price: "
read costPrice

printf "Enter Selling price: "
read sellPrice

if [ $costPrice -gt $sellPrice ]
then
    echo "Loss of -"$(($costPrice-$sellPrice))
elif [ $costPrice -lt $sellPrice ]
then
    echo "Profit of +"$(($sellPrice-$costPrice))
else
    echo "No profit No loss"
fi
