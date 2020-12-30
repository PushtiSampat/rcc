# 8.

# In a college, students are allowed to select any one elective subject during his studies. Create two files by entering the data as mentioned below (you may skip the heading line if required) :

# File : elective.dat
#       Code     Game
# ---------------------------
#     101 AI
#     102 Computer Graphics
#     103 Parallel Processing
#     104 Data Mining

# File : students.dat
# RollNo.      Name     Code
# ------------------------------
# 1          Sonal            101
# 2          Madhu          101
# 3          Mahim          103
# 4          Esha              104


# Write a shell script to list the students according to their choice of electives …

# Eg.  AI :- Sonal, Madhu
#        Computer Graphics: -
#        Parallel Processing :- Mahim
#        Data Mining :- Esha



electiveFile="elective.dat"

while IFS= read -r line; do
    i=1
    for word in $line; do
        if [ $i -eq 1 ]; then
            # Here on awk, we will use `print`, not `printf` so that we can seperate persons
            output=$(cat electiveStudents.dat | grep $word | awk '{print $2}')
            # if test -z "$output"; then
            #     printf ""
            # else
                # Here awk will print all but very first column:
                echo -n $line | awk '{$1=""; printf $0}'
                echo -n ":- "
                for person in $output; do
                    echo -n $person ","
                done
                echo
            # fi
        fi
        i=$((i+1))
    done
done < $electiveFile


: '
Output

 AI:- Sonal ,Madhu ,
 Computer Graphics:- 
 Parallel Processing:- Mahim ,
 Data Mining:- Esha ,
'
