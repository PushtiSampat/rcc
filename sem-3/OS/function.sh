# 9. Check whether the entered no. is prime or not.
#! /bin/bash

# Define your function here
Hello () {
   return $#
}

# Invoke your function
Hello Ajinkya Rathod

# Capture value returnd by last command
ret=$?

echo "There are $ret arguments in Hello function"
