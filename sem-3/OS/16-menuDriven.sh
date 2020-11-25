# 16. Write a shell script to display the menu driven interface :-
# 1) list all files of the current directory 
# 2) print the current directory 
# 3) print the date 
# 4) print the users otherwise display "Invalid Option".


#! /bin/bash

echo "1) List all Files"
echo "2) Print Current Directory"
echo "3) Print Date"
echo "4) Print Users"

read choice

case $choice in
    1)  ls
        ;;
    2)  pwd
        ;;
    3)  echo `date +%d-%B-%Y`
        ;;
    4)  awk -F: '{ print $1}' /etc/passwd
        ;;
    *)  echo "Invalid Option"
esac
