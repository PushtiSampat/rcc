# 22. Write a script which reports name and size of
# all files in a directory  whose sizes exceed 1000.
# The filenames should be printed in the descending order of their sizes.
# The total no. of files must be reported.

#! /bin/bash
ls --sort=size -l | awk '$5 >= 1000 {print $5,$9}'
