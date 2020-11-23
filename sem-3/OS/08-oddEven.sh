# 8. Check whether the entered no. is odd or even.

printf "Enter num: "
read num

if [ $(($num % 2)) -eq 0 ]
then
    echo "Even"
else
    echo "Odd"
fi
