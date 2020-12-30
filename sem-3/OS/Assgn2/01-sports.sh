# 1.
# In a college, students are allowed to select any one sporting event during his studies. Create two files as mentioned below :

# File : sports.dat
#       Code     Game
# ---------------------------
#     101 Cricket
#     102 Football
#     103 Tennis
#     104 Badminton

# File : students.dat
# Name     Code
# ------------------------------
# Aamir     101
# Sharukh  103
# Salman   103
# Ajay       102


# Write a shell script to list the students according to their choice of games …
# Eg.  Cricket :  Aamir
#         Football : Ajay
#         Tennis :   Sharukh, Salman

sportFile="sports.dat"

while IFS= read -r line; do
    i=1
    for word in $line; do
        if [ $i -eq 1 ]; then
            # Here on awk, we will use `print`, not `printf` so that we can seperate persons
            output=$(cat students.dat | grep $word | awk '{print $1}')
            if test -z "$output"; then
                printf ""
            else
                echo -n $line | awk '{printf $2}'
                echo -n ": "
                for person in $output; do
                    echo -n $person ","
                done
                echo
            fi
        fi
        i=$((i+1))
    done
done < $sportFile


: '
Output

Cricket: Aamir ,
Football: Ajay ,
Tennis: Sharukh ,Salman ,
'
