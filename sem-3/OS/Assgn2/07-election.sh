# 7

# Create a file “election.dat” which contains the Election details for a specific city.

# Field               Description
# ------------------------------------
# Idno                Numeric    - Unique
# Name              Character – Voter’s Name
# Sex                 Character – M / F
# Age                Numeric  
# Ward              Numeric  – Ward no. / Division no. of the city.

# Sample data:
# e101-abhishek-M-35-44
# e102-ashutosh-M-97-14
# e103-anamika-F-21-50

# Suppose the same file is to be modified after 4 years. Write a shell script to simulate this process.
# Your program must update the age of all People ( Add 4 years to age). In case if the age exceeds 99 then delete the record from the file, assuming that the person is dead.

# Display the election.dat and final output of your program.

file='election.dat'

# Adding 4 years
awk 'BEGIN{ FS=OFS="-";newAge=0 } { newAge=$4+4; {$4 = newAge}; print }' $file > .temp.txt
mv .temp.txt election.dat


# Deleting People with age > 100 yrs

# Just Display Names < 100 Years
# awk 'BEGIN{ FS=OFS="-";newAge=0 } $4 > 100 { next } { print }' "$file"

# Changing inplace
gawk -i inplace 'BEGIN{ FS=OFS="-";newAge=0 } $4 > 100 { next } { print }' "$file"


# Explanation:

#     awk:                       invoke the awk command
#     '...':                     everything enclosed by single-quotes are instructions to awk
#     BEGIN{FS=OFS=":"}:         Use : as delimiters for both input and output. FS: Field Separator. OFS: Output Field Separator.
#     if (NR==1) {$3 = "XXXX"};: If Number of Records (NR) read so far is 1, then set the 3rd field ($3) to "XXXX".
#     print:                     print the current line
#     input_file:                name of your input file.
