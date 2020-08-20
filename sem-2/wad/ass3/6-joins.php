

<!-- ====================================================================== -->
<!-- 6-joins-query.php -->

<?php
require_once ('config.php');


// ==========================================================================
echo "a) Find out the products, which have been sold to ‘Ivan Bayross’.";
$query = "SELECT d.product_no,p.description from sales_order_details d , product_master p , client_master c,sales_order s
where p.product_no=d.product_no and s.s_order_no=d.s_order_no and c.client_no=s.client_no and c.name='Ivan Bayross';";

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
echo "b) Find out the products and their quantities that will have to be delivered in the current month.";

$currmonth = date('m', strtotime("now"));

$query = "SELECT d.product_no,p.description,sum(d.qty_ordered)
from sales_order_details d,sales_order s,product_master p
where p.product_no=d.product_no and s.s_order_no=d.s_order_no and MONTH(dely_date) = $currmonth
group by d.product_no,p.description;";

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
echo "c) Find the product_no and description of constantly sold i.e. rapidly moving products.";
$query = "SELECT distinct p.product_no,p.description from product_master p ,sales_order_details d
where p.product_no=d.product_no;";

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
echo "d) Find the name of clients who have purchase ‘CD Drive’.";
$query = "SELECT distinct s.client_no,c.name from sales_order_details d,sales_order s,product_master p,client_master c
where p.product_no=d.product_no and s.s_order_no=d.s_order_no and c.client_no=s.client_no and p.description='CD Drive'";

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



// ==========================================================================
echo "e) List the product_no and order_no of customers having qty_ordered less than 5 from the sales_order_details table for the product ‘1.44 Floppies’.";
$query = "SELECT d.product_no,d.s_order_no from sales_order_details d,sales_order s,product_master p
where s.s_order_no=d.s_order_no and p.product_no=d.product_no and d.qty_ordered<5 and p.description='1.44 Floppies';";

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
echo "f) Find the products and their quantities for the orders placed by ‘Ivan Bayross’ and ‘Vandana Saitwal’.";
$query = "SELECT d.product_no,p.description,sum(qty_ordered)\"Qty Ordered\"
from sales_order_details d,sales_order s,product_master p,client_master c 
where s.s_order_no=d.s_order_no and p.product_no=d.product_no and c.client_no=s.client_no
and (c.name='Ivan Bayross' or c.name='Vandana Saitwal')
group by d.product_no,p.description;
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
echo "g) Find the products and their quantities for the orders placed by client_no ‘C00001’ and ‘C00002’.";
$query = "SELECT s.client_no,d.product_no,p.description ,sum(qty_ordered)\"Qty_ordered\"
from sales_order s,sales_order_details d,product_master p,client_master c
where s.s_order_no=d.s_order_no and d.product_no=p.product_no and s.client_no=c.client_no
group by s.client_no,d.product_no,p.description
having s.client_no='C00001' or s.client_no='C00002';";

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


?>



