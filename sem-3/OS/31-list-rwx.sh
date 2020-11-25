# 31. The script displays a list of all files in the current
# directory to which you have read, write and execute permissions.

#! /bin/bash
ls -l | awk '$1 ~ /rwx/'
