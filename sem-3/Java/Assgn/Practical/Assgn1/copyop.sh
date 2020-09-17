#! /usr/bin/env bash

# If Arguments as less than 2
if [ $# -lt 2 ]
then
    echo "Provide atleast 2 Arguments"
    exit 1
fi

# Initialzing count with 1
count=1

#Count Arguments
# echo "Total Arguments: $#"

my_middle_args=()

for arg in $*; do
    # First Argument
    if [ $count -eq 1 ]
    then
        my_first_arg=$arg

    # Last Arguments
    elif [ $count -eq $# ]
    then
        my_last_arg=$arg

    # Middle Arguments
    else
        echo "$arg"
        my_middle_args+=( $arg )
    fi

    # Count value Increment
    ((count++)) 
done

# echo "First Argument:$my_first_arg"
# echo "Last Argument:$my_last_arg"
# echo "Middle Args: ${my_middle_args[@]}"

output=$(java $my_first_arg $my_middle_args)

# Writing output to last Argument which is file name
printf "\n\n/* ===========================================================\n" >> $my_last_arg
printf "Output: \n\n" >> $my_last_arg
printf "$output" >> $my_last_arg
printf "\n" >> $my_last_arg
printf "\n =========================================================== */" >> $my_last_arg

echo "Added the following output to <$my_last_arg>"
echo $output
