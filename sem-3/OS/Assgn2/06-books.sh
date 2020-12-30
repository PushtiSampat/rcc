# 6.

# Write a Shell script  to generate summary from  a file “books.dat” which contains the following details :

# Field             Description
# -------------------------------------------------------------------------
# No                Numeric (4) – uniquely identifies each book.
# Title             Alphanumeric(30) – title of the book
# Author          Character(20) – Author of the book
# Publisher      Character(20) – Publisher (PHI , TMH, BPB…)
# Edition         Numeric (2)

# Sample Data:
# b1001Programming in Java           Balagurusway        TMH                 Second
# b1002Computer Networks             Tanenbaum            Pearson             Fifth
# b1003Operating Systems                Chaudhari              Jaico                 First

# After creating the file do the followings :
#     • Your script must replace all the BPB publisher with TMH.
#     • List the titles with the name ‘Java’.
#     • List the books written by ‘Balaguruswamy
#     • List the books which are not the first edition

replacePublisher(){
    # https://unix.stackexchange.com/questions/626204/how-to-replace-only-specific-20-characters-using-sed/626205
    # (Asked By Me)
    # sed -i 's/^\(.\{55\}\)BPB\( \{17\}\)/\1THM\2/' books.dat

    sed '
      :1
    s/^\(.\{55,72\}\)BPB/\1THM/
    t1' $file

    # -i to change in actual File
    sed -i '
      :1
    s/^\(.\{55,72\}\)BPB/\1THM/
    t1' $file
      echo
}

listJavaTitles(){
    while IFS= read -r line; do
        # Start from 5th index, and increase 30 index (Last index: 5+30=35)
        echo ${line:5:30} | grep -i "java"
    done < $file
    echo
}

balaguruswamyBooks(){
    while IFS= read -r line; do
        echo ${line:35:20} | grep -i "Balaguruswamy"
    done < $file
    echo
}

noFirstEditionBooks(){
    while IFS= read -r line; do
        # -2 coz edition is at last 2 characters
        echo ${line: -2} | awk '{ if($1 != 1) print $1; }'
    done < $file
}

file='books.dat'

echo "1) Replace Publisher"
replacePublisher

echo "2) List titles with name \`Java\`"
listJavaTitles

echo "3) List Books of Balaguruswamy"
balaguruswamyBooks

echo "4) List books which are not first edition"
noFirstEditionBooks


: '
Output

1) Replace Publisher
b1001Programming in Java By BPB    Balaguruswamy       THM                 2
b1002Computer Networks             Tanenbaum           Pearson             5
b1003Operating Systems             Chaudhari           Jaico               1

2) List titles with name `Java`
Programming in Java By BPB

3) List Books of Balaguruswamy
Balaguruswamy

4) List books which are not first edition
2
5
'
