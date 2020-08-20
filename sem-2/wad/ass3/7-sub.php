

<!-- ====================================================================== -->
<!-- 7-sub-query.php -->

<?php
require_once ('config.php');


// ==========================================================================
echo "a) Find the product_no and description of non-moving products i.e. products not being sold.";
$query = "SELECT product_no,description from product_master
where product_no not in(select product_no from sales_order_details);";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . $fetch[1] . "</td>";
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
echo "b) Find the customer name, address1, address2, city and pin code for the client who has placed order no ‘O19001’.";
$query = "SELECT name,address1,address2,city,pincode from client_master
where client_no in (select client_no from sales_order
where s_order_no='O19001');

";

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
			echo "<td>" . $fetch[4] . "</td>";
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
echo "c) Find the client names who have placed orders before the month of May’96.";
$query = "SELECT client_no,name from client_master where client_no in(select client_no from sales_order 
where s_order_date < '1996-05-01');";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . $fetch[1] . "</td>";
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
echo "d) Find out if the product ‘1.44 Drive’ has been ordered by any client and print the clint_no, name to whom it was sold.";
$query = "SELECT client_no,name from client_master where client_no
in (select client_no from sales_order where s_order_no in (select s_order_no 
from sales_order_details where product_no in(select product_no 
from product_master where description='1.44 Drive')));
";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . $fetch[1] . "</td>";
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
echo "e) Find the names of clients who have placed orders worth Rs.10000 or more.";
$query = "SELECT name from client_master where client_no in(select client_no from sales_order
where s_order_no in (select s_order_no from sales_order_details
where (qty_ordered*product_rate)>=10000));
";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
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


