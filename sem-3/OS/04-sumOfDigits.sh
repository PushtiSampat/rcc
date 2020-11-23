# 4. If a five digit number is entered through the keyboard,
# calculate the sum of its digits.

total=0

echo "Enter a number"
read num

while [ $num -gt 0 ]
do
    total=$((total+num%10))
    ((num/=10))
done

echo "Total:" $total
