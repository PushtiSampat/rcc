# 4

# Write a shell script to generate summary from a file : “student.dat” with following format :

# Student_no : student_name : gender : marks1 : marks2 : marks3

# Each field must be separated by a delimeter ‘-‘

# Process the following queries:
#     • Calculate the total marks of each student
#     • Calculate the percentage of marks for each student
#     • Count the total number of male and female students
#     • Count the total number of students who pass and those who fail.

file='student.dat'

males=0
females=0
passed=0
failed=0

while IFS= read -r line; do

    # Extracting Name
    name=$(cut -d "-" -f2 <<< $line)
    
    # Extracting Gender
    gender=$(cut -d "-" -f3 <<< $line)

    # Counting Males and Females
    if [ $gender = "m" ]; then
        males=$((males+1))
    else
        females=$((females+1))
    fi

    # Extracting Marks
    sub1=$(cut -d "-" -f4 <<< $line)
    sub2=$(cut -d "-" -f5 <<< $line)
    sub3=$(cut -d "-" -f6 <<< $line)

    # Counting Total
    total=$(($sub1+$sub2+$sub3))

    # Calculating Percentage
    per=$(echo "scale=1; $total / 3" | bc)

    # Counting Failed And passed
    # Floating Point if statement Comparison
    if (( $(echo "$per > 30" | bc -l) )); then
        failed=$((failed+1))
    else
        passed=$((passed+1))
    fi
    echo $name": " $per"%" "[Total: $total]"
done < $file

echo
echo "Males:" $males
echo "Females:" $females

echo "Passed:" $passed
echo "failed:" $failed


: '
Output

Ajinkya:  85.6% [Total: 257]
Aneri:  9.3% [Total: 28]
Ghanshyam:  99.6% [Total: 299]

Males: 2
Females: 1
Passed: 1
failed: 2
'
