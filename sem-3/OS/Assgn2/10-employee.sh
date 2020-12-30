# Create two files employee.dat and departments.dat and add atleast 10 records in the following format :

# employee.dat
# emp_id:department_id:birthdate
# e101:M1:11-01-1960
# e102:C1:21-03-1973
# e103:M2:21-03-1973
# e104:C1:21-03-1973
# e105:B1:08-10-1965
# e101:M1:11-11-1964

# departments.dat
# departmend_id:department_name
# B1:Botany
# C1:Chemistry
# M1:Mathematics
# M2:Management

# Write a shell script to do the followings:
#     1) List all the employee_ids department-wise
#     2) List the employee_ids born after 1970
#     3) List the employee_ids according to birthdate in sorted order


employeeFile='employee.dat'
departmentFile='departments.dat'


# 1) List all the employee_ids department-wise
printf "1) List all the employee_ids department-wise\n\n"
sortedData=$(sort -t ':' -k 2 $employeeFile | awk -F ":" {'print $1; print $2'})
i=1
for item in $sortedData; do
    if [ $i -eq 1 ];then
        printf "$item "
        i=$((i+1))
    else
        grep $item $departmentFile | awk -F ':' {'printf $2'}
        echo
        i=1
    fi
done


# 2) List the employee_ids born after 1970
printf "\n\n2) List employee_ids born after 1970\n\n"
echo "- Using cut, then awk "
cut -d ":" -f3 $employeeFile | awk -F "-" {'if($3 > 1970) print $3'}

# or
echo "- Only using awk "
awk -F ":" {'print $3'} $employeeFile | awk -F "-" {'if($3 > 1970) print $3'}


# 3) List the employee_ids according to birthdate in sorted order
printf "\n\n3) List the employee_ids according to birthdate in sorted order\n\n"
# -n is for numeric, -k is for field number
awk -F ":" {'print $3'} $employeeFile | sort -t '-' -nk 3 -nk 2 -nk 1


: '
Output

1) List all the employee_ids department-wise

e109 Botany
e108 Chemistry
e105 Chemistry
e106 Chemistry
e101 Mathematics
e110 Mathematics
e102 Mathematics
e103 Mathematics
e104 Mathematics
e107 Management


2) List employee_ids born after 1970

- Using cut, then awk 
1974
1973
1973
1973
1973
1973
1973
1973
1973
1973
- Only using awk 
1974
1973
1973
1973
1973
1973
1973
1973
1973
1973


3) List the employee_ids according to birthdate in sorted order

28-01-1973
29-01-1973
30-01-1973
21-02-1973
21-03-1973
25-06-1973
25-06-1973
18-10-1973
11-11-1973
01-01-1974
'
