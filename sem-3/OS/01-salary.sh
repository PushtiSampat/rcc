# 1. Basic salary of a person is input through the keyboard.
# His dearness allowance is 40% of basic salary
# and house rent is 20% of basic salary.
# Write a program to calculate the gross pay.

salary=${1}

dearnessAllowance=$(( $salary*40/100  ))

houseRent=$(( $salary*20/100  ))

total=$(( $salary+$dearnessAllowance+$houseRent ))

echo "salary: $salary"
echo "dearnessAllowance: $dearnessAllowance"
echo "houseRent: $houseRent"
echo "total: $total"
