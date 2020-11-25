# 28. Write a shell script which deletes all the lines containing
# the word "unix" in the files supplied as arguments to it.

#! /bin/bash
# =========================================================================
# sed '/foo/d' deleteFromFile.txt

#  the substring foo inside the foobar string is also replaced. 
# If this is not the wanted behavior, use the word-boundary expression (\b)
# at both ends of the search string.
# This ensures the partial words are not matched.

# =========================================================================

word="UNIX"

# Read all args
for i; do
    # I is for Insensitive
    # d is for delete
    # I must be written first
    sed -i "/\b$word\b/Id" $i
done

