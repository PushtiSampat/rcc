# 5. The file /etc/passwd contains info about all users.
# Write a program which would receive the logname during execution,
# obtain information about it from the file and display the information
# on screen in some appropriate format. (Hint : use cut)
# eg. Logname : , UID : , GID : , Default working directory : , Default working shell :

filepath="/etc/passwd"

cut -d ":" -f 1,3,4,5,6,7 $filepath --output-delimiter=' | '
