# --------------------------------------------------------------
# The -r option passed to
# read command prevents backslash escapes from being interpreted

# Add IFS= option before read command to prevent
# leading/trailing whitespace from being trimmed 
# --------------------------------------------------------------
while IFS= read -r line
do
    echo $line
done < "$filepath"

