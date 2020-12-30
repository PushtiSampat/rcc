# 2

# Write a shell script to generate summary from the sales.dat file.
# Sales made by 3 salesman by selling 3 products are entered in a file. Add atleast 10 records. The format is as shown below:
# Salesman:Product1:Product2:Product3

# Sample data:
# Mr. Abhishek Sharma:21:29:12
# Mr. Akash Srivastava:11:15:28
# Mr. Abhilash Dwivedi:31:04:13


# Calculate the followings :
#     • Total sales of the company
#     • Highest sold product
#     • Best salesman (who sold the most)
#     • Worst salesman (who sold the least)


file='sales.dat'
# Setting bestSalesman, worstSalesman as First Record of Data
bestSalesman=$(head -1 $file | cut -d ":" -f1)
worstSalesman=$bestSalesman


# Setting Initial Sales to 0
product1_Sales=0
product2_Sales=0
product3_Sales=0
totalSales=0


# Setting bestSalesTotal, worstSalesTotal as First Record of Data
p1=$(head -1 $file | cut -d ":" -f2)
p2=$(head -1 $file | cut -d ":" -f3)
p3=$(head -1 $file | cut -d ":" -f4)
currentPersonSales=$(($p1+$p2+$p3))
bestSalesTotal=$currentPersonSales
worstSalesTotal=$currentPersonSales


# Reading Line By Line
while IFS= read -r line; do

    # Extracting Name
    name=$(cut -d ":" -f1 <<< $line)

    # Extracting Sales Amount
    p1=$(cut -d ":" -f2 <<< $line)
    p2=$(cut -d ":" -f3 <<< $line)
    p3=$(cut -d ":" -f4 <<< $line)

    # Counting Total Sales of Each Product
    product1_Sales=$(($product1_Sales+$p1))
    product2_Sales=$(($product2_Sales+$p2))
    product3_Sales=$(($product3_Sales+$p3))
    
    # Counting totalSales of Current Person
    currentPersonSales=$(($p1+$p2+$p3))

    # Evaluating Overall Sales
    totalSales=$(($totalSales+$currentPersonSales))

    # Figuring Out Best Salesman
    ((currentPersonSales > bestSalesTotal)) && bestSalesman=$name && bestSalesTotal=currentPersonSales

    # Figuring Out Worst Salesman
    ((currentPersonSales < worstSalesTotal)) && worstSalesman=$name && worstSalesTotal=currentPersonSales

    # Displaying All Records
    echo $name $p1 $p2 $p3 ":" $currentPersonSales
done < $file


# echo "Product1 Sales: " $product1_Sales
# echo "Product2 Sales: " $product2_Sales
# echo "Product3 Sales: " $product3_Sales


# Figuring Out the Highest Sold Product
allSales=($product1_Sales $product2_Sales $product3_Sales)
max=${allSales[0]}
i=0
for n in "${allSales[@]}" ; do
    i=$((i+1)) && ((n > max)) && max=$n && p=$i
done


# Displaying Final Result
echo 
echo "TotalSales:" $totalSales
echo "Highest Sold Product: \`Product"$p\` \(Sales: $max\)
echo "Best Salesman:" $bestSalesman
echo "Worst Salesman:" $worstSalesman


: '
Output

Mr. Abhishek Sharma 21 29 12 : 62
Mr. Akash Srivastava 11 15 28 : 54
Mr. Abhilash Dwivedi 31 04 13 : 48
Mr. Ajinkya Rathod 45 89 56 : 190
Mrs. Aneri Khadodara 12 59 75 : 146
Mrs. Steffi Rathod 78 12 56 : 146
Mr. Ghanshyam Pandey 26 15 59 : 100
Mr. Hari Krushna 15 26 35 : 76
Mr. Krishna Vasudev Yadav 12 45 78 : 135
Mr. Sahajanand Swami 89 56 23 : 168

TotalSales: 1125
Highest Sold Product: `Product3` (Sales: 435)
Best Salesman: Mr. Ajinkya Rathod
Worst Salesman: Mr. Akash Srivastava
'
