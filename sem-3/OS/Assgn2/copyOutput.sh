file=$1

cp $file .temp.txt
printf "\n\n: '\nOutput\n\n" >> .temp.txt 
./$file >> .temp.txt
mv .temp.txt $file
echo "'" >> $file
