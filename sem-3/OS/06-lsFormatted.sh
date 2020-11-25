# 6. The script will receive the filename or filename
# with its full path, the script should obtain information
# about this file as given by "ls -l" and display it in proper format.

#! /bin/bash

# ------------------------------------------
echo "---------- Using stat----------"
stat -c "%A %h %U %G %s %.19y %n" *


# -------------------------------------------
printf "\n---------- Using ls -l ----------\n"

# in 'awk', string Without quotes are interpreted are variables
# Without Concatenation
ls -l | tr -s ' ' | cut -d ' ' -f 1-9 -s | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,"\033[32;1m"$9"\033[0m"}'

# `|` is a string and thats why it is written in double quotes
# With Concatenation
echo ""
ls -l | tr -s ' ' |cut -d ' ' -f 1-9 -s | awk '{print $1" | "$3" | "$4" | "$5" | "$6,$7" | "$8" |\033[32;1m "$9 "\033[0m"}'



# ------------------------------------------------------
# EXPLANATION:

# ---------- tr ----------
# `tr` stands for translate
# we use `tr` command along with squeeze option (-s flag )
# to convert all multiple consecutive spaces to a single space


# ---------- apply style on your string ----------
# https://stackoverflow.com/questions/2924697/how-does-one-output-bold-text-in-bash

# 1. echo -e: The `-e` option means that escaped (backslashed) strings will be interpreted
# 2. \033: escaped sequence represents beginning/ending of the style
# 3. lowercase m: indicates the end of the sequence
# 4. 1: Bold attribute (see below for more)
# 5. [0m: resets all attributes, colors, formatting, etc.

# 0 - Normal Style
# 1 - Bold
# 2 - Dim
# 3 - Italic
# 4 - Underlined
# 5 - Blinking
# 7 - Reverse
# 8 - Invisible
