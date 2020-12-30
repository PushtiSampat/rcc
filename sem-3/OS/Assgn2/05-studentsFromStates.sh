# 5
# A reputed MCA institute of Gujarat has students from various states. A sample file “students.dat” is shown as under :

# State                M         F
# -----------------------------------
# Gujarat            18        12
# Maharashtra    12        04
# M.P.                08        04
# UP                   05        00
# Rajasthan        07        00

# Total Male candidates are 50 and Female are 20. Write a shell script to generate a Statewise Candidate Distribution Report as under :

#                              STATEWISE CANDIDATES LISTING
# ---------------------------------------------------------------------------------------------
#              STATE                %MALE              %FEMALE           TOTAL
# ---------------------------------------------------------------------------------------------
#              GUJARAT               36                         60                         30
#              MAHARASHTRA  24                         20                         16
# ……………………….. ………. And so on …………………………………..


file='statewiseStudents.dat'

# Removing Extra Spaces
cat $file | tr -s " " > .temp.txt && mv .temp.txt $file

totalMales=50
totalFemales=20

printf " \t\tSTATEWISE CANDIDATES LISTING\n"
echo "-------------------------------------------------------------"
printf "%-30s%s \t %s \t%s\n" "STATE" "%MALE" "%FEMALE" "TOTAL"
echo "-------------------------------------------------------------"

padlength=40
while IFS= read -r line; do

    # Extracting State
    state=$(cut -d " " -f1 <<< $line)

    # Extracting Number of Students and Removing Leading Zeros
    male=$(cut -d " " -f2 <<< $line | sed "s/^0*//")
    female=$(cut -d " " -f3 <<< $line | sed "s/^0*//")
    

    # What if there are 0 students, the string 0 will be erased
    # So, if cut return nothing, we will set variable to 0

    # $female must be written in double quotes, so that we can make string comparison
    if [ "$female" == "" ]; then
        female=0
    fi
    if [ "$male" == "" ]; then
        male=0
    fi

    malePer=$(echo "scale=0; $male * 100 / $totalMales" | bc)
    femalePer=$(echo "scale=0; $female * 100 / $totalFemales"  | bc)

    # printf "%-30s%s \t %s \t\t\n" "$state" "$malePer" "$femalePer"
    printf "%-30s%s \t %s \t\t%s\n" "$state" "$malePer" "$femalePer" "$(($male+$female))"

done < $file
