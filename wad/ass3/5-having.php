<?php
require_once ('config.php');

// ==========================================================================
echo "a) Print the description and total qty sold for each product.";
$query = "SELECT s.product_no,p.description, sum(s.qty_ordered) from sales_order_details s,product_master p
where p.product_no=s.product_no
group by s.product_no,p.description;;";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . $fetch[1] . "</td>";
			echo "<td>" . $fetch[2] . "</td>";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";


// ==========================================================================
echo "b) Find the value of each product sold.";
$query = "SELECT s.product_no,p.description,sum(s.qty_disp*s.product_rate) \"Sales Per Product\" from
sales_order_details s,product_master p where p.product_no=s.product_no
group by s.product_no,p.description;";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . $fetch[1] . "</td>";
			echo "<td>" . $fetch[2] . "</td>";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";



// ==========================================================================
echo "c) Calculate the average qty sold for each client that has a maximum order value of 15000.00.";
$query = "SELECT c.client_no,c.name,avg(s.qty_disp)  from sales_order_details s ,sales_order so,client_master c
where c.client_no=so.client_no and so.s_order_no=s.s_order_no
group by c.client_no,c.name having max(s.qty_ordered*s.product_rate)>15000;";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . $fetch[1] . "</td>";
			echo "<td>" . $fetch[2] . "</td>";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";




// ==========================================================================
echo "d) Find out the sum total of all the billed orders for the month of January.";
$query = "SELECT s.s_order_no,s.s_order_date,sum(so.qty_ordered*so.product_rate)\"Order Billed\",sum(so.qty_disp*so.product_rate) \"Total Amount\" from sales_order s, sales_order_details so
 where so.s_order_no=s.s_order_no and s.billed_yn='Y' and month(s_order_date)='01'
 group by s.s_order_no,s.s_order_date;";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . $fetch[1] . "</td>";
			echo "<td>" . $fetch[2] . "</td>";
			echo "<td>" . $fetch[3] . "</td>";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";


?>