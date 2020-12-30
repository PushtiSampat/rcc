# 9.

# Create two files: subjects.dat and students.dat containing the subject details and the student details. Sample data is as shown below:

# subjects.dat
# Course_id-Semester_id-Subject_id-Subject_name
# CS-1-1-FCO
# CS-1-2-FOP
# CS-1-3-SL
# CS-2-1-DS
# CS-2-2-DBMS
# CS-3-1-OS
# CS-3-2-JAVA

# faculty.dat
# Faculty_id:Semester_id:Subject_id
# F1-2-1
# F2-3-2
# F3-1-3
# F1-1-1

# Write a shell script to list the faculties and their respective subjects. Sample Output will be :
# F1 : FCO, DS
# F2 : JAVA
# F3 : SL

facultyFile='faculty.dat'
subjectFile='subjects.dat'

facultyIds=$(cut -d "-" -f2,3 $facultyFile)
for f_id in $facultyIds; do
    faculty=$(cat $facultyFile | grep $f_id | awk -F "-" '{print $1}')
    subject=$(cat $subjectFile | grep $f_id | awk -F "-" '{print $4}')
    echo $faculty ":" $subject
done


: '
Output

F1 : DS
F2 : JAVA
F3 : SL
F1 : FCO
'
