# 10. Check whether the entered year is a leap year or not.


printf "Enter num: "
read num

if [ $(($num % 400)) -eq 0 ]; then
    echo "Leap"
    exit
elif [ $(($num % 100)) -eq 0 ]; then
    echo "Not Leap Year"
    exit
elif [ $(($num % 4)) -eq 0 ]; then
    echo "Leap"
    exit
else
    echo "Not Leap Year"
fi
