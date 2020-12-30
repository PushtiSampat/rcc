# 3.

# Create a file “medals.dat” which contains the details of medals won by each country in Olympics. The data in the file may be as given below :
# ( Country name is Primary key.)

# Country         Gold   Silver  Bronze
# ---------------------------------------------
# India                 21      12         15
# Pakistan            12      10         08
# USA                 10      14         19
# Srilanka            00      09         07
# ………….and so on………………..

#     • Write a shell script which will ask the user to enter the Country name, further modify the no. of medals for that country.
#     • Delete all the countries who get zero Gold medals.
#     • Calculate the total no. of medals won by each country.
#     • Find the country with highest Gold medals.


modifyMedals(){
    # 1. Modifying Medals =================================

    # Reading Country Name from User
    read -p "Enter Country Name:" country
    echo $country

    # Finding If Country Exists
    findCountry=$(cat $file | grep $country)
    if test -z "$findCountry";then
        echo "Country Not Found"
        exit
    fi

    read -p "Enter Medals for $country: " gold silver bronze

    # Extracting The text which needs to be replaced
    text_to_replace=$(cat $file | grep $country)

    # Setting New Text
    new_text="${country} ${gold} ${silver} ${bronze}"

    # Modifying Data
    sed -i "/$text_to_replace/c\\$new_text" $file
    echo "Updated Medals Successfully"

    # Displaying Updates
    updatedText=$(cat $file | grep $country)
    echo $updatedText
}

deleteData(){
    # Delete all the countries who get zero Gold medals

    # As countries is primary key, we can delete line using country
    countries=$(cut -d " " -f1,2 $file | awk '{if($2==0)print$1}')
    for country in $countries; do
        sed -i "/$country/d" $file
    done
}

calculateMedals(){
    # Reading Line By Line
    while IFS= read -r line; do
        # Displaying Only First Word
        for word in $line; do
            echo -n $word": "
            break
        done

        medals=$(echo $line | grep -o -E '[0-9]+' | sed "s/^0*//")

        # Explanation 
        # sed "s/^0*//": To remove Leading Zeros so that Arithmetic operation can be performed

        # -E
        # Interpret PATTERNS as extended regular expressions (EREs, see below).

        # -o
        # Print only the matched (non-empty) parts of a matching line, with each such part on a separate output line.

        total=0
        for medal in $medals; do
            # Double Brackets does Arithmetic Addition
            total=$(($total+$medal))
        done
        echo $total
        
    done < $file
}

highestGoldMedals(){
    max=0
    while IFS= read -r line; do
        gold=$(cut -d " " -f2 <<< $line)
        if [ $gold -gt $max ]; then
            countryWithHighestGold=$(cut -d " " -f1 <<< $line)
            max=$gold
        fi
    done < $file
    echo "Country With Highest Gold:" $countryWithHighestGold \($max\)
}

file='medals.dat'

# Removing Extra Spaces
cat $file | tr -s " " > .temp.txt && mv .temp.txt $file


echo "1) Modify Medals"
echo "2) Delete Countries with 0 Gold Medals"
echo "3) Calculate Total Medals Country Wise"
echo "4) Country With Highest Gold Medals"

read choice

case $choice in
    1)  modifyMedals
        ;;
    2)  deleteData
        ;;
    3)  calculateMedals
        ;;
    4)  highestGoldMedals
        ;;
    *)  echo "Invalid Option"
esac
