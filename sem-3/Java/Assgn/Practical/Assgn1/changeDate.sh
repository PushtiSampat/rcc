for file in *.java

do 
    sed -i 's/21-Aug-2020/17-Sep-2020/g' $file
    echo "Date changed in: $file"
done
