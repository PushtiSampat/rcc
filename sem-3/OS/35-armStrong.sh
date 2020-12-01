# 35. Print armstrog nos. from 1 to 500. 

checkArmstrong(){
    digits=0
    n1=$1

    n2=$n1
    n3=$n1

    while [ $n2 -gt 0 ]; do
        ((digits++))
        ((n2/=10))
    done

    total=0
    while [ $n1 -gt 0 ]; do
        rem=$((n1%10))
        power=$(echo "$rem^$digits" | bc)
        total=$(echo "$total+$power" | bc)
        ((n1/=10))
    done

    if [ $total -eq $n3 ]; then
        return 1
    else
        return 0
    fi
}

num=1
while [ $num -le 300 ]; do
    checkArmstrong $num
    ifArmstrong=$?

    if [ $ifArmstrong -eq 1 ]; then
        printf "$num "
    fi

    num=$((num+1))
done
