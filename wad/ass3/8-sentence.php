<?php
require_once ('config.php');


// ==========================================================================
echo "a) Print information from product_master, sales_order_detail tables in the following format for all the records:<br>
<b>{Description} worth Rs. {total sales for the product} was sold.</b>";

$query = "SELECT p.description, sum(s.qty_disp * s.product_rate) FROM sales_order_details s, product_master p 
WHERE p.product_no = s.product_no
GROUP BY s.product_no, p.description
";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td style= 'border-right: none; text-align: right;'>Product: <b>" . $fetch[0] . " </b> worth Rs. -></td>";
			echo "<td><b>" . $fetch[1] . "</b> were sold</td>";
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
echo "b) Print information from product_master, sales_order_detail tables in the following format for all the records:
{Description} worth Rs. {total sales for the product} was ordered in the month of {order_date in month format}.";
$query = "SELECT * FROM product_master WHERE 1 = 2;";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "Nai Ata";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>Nai Ata mereko No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";



// ==========================================================================
echo "c) Print information from client_master, product_master, sales_order tables in the following format for all the records:
{cust_name} has placed order {order_no} on {order_date}.";
$query = "SELECT c.name, s.s_order_no, s.s_order_date from client_master c, sales_order s WHERE c.client_no = s.client_no";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>Cust. Name: <b>" . $fetch[0] . "</b> has ordered </td>";
			echo "<td>Order No. : <b>" . $fetch[1] . "</b> on </td>";
			echo "<td> <b>" . $fetch[2] . "</b></td>";
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