# 14. Write a shell script to display the date with the format :-
# 25th October 2005 is a Tuesday.


d=`date +%d\ %B\ %Y\ is\ a\ %A`
echo $d
