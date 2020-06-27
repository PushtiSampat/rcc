<?php
require_once('config.php');

// ================================
echo "a) Find the name of all clients having ‘a’ as the second letter in their names";
$query = "SELECT name from client_master where name like '_a%'";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	while($fetch = mysqli_fetch_array($result)) {
		echo "<tr><td>";
		echo $fetch[0];
		echo "</td></tr>";
	}
	echo "</table>";
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";



// ================================
echo "b) Find out the clients who stay in a city whose second letter is ‘a’.";
$query = "SELECT name from client_master where city like '_a%' ;";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	while($fetch = mysqli_fetch_array($result)) {
		echo "<tr><td>";
		echo $fetch[0];
		echo "</td></tr>";
	}
	echo "</table>";
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";


// ================================
echo "c) Find the list of all client who stay in ‘Bombay’ or ‘Delhi’.";
$query = "SELECT name,city  from client_master where city in('Bombay','Delhi');";

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


// ================================
echo "d) Print the list of client whose bal_due is greater then value 10000.";
$query = "SELECT name,bal_due from client_master where bal_due > 10000 ;";

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


// ================================
echo "e) Print the information from sales_order table for order placed in the month of January.";
$query = "SELECT s_order_no,s_order_date from sales_order where s_order_date in
(select s_order_date from sales_order where MONTH(s_order_date)='1');";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . date('M d, \'y', strtotime($fetch[1])) . "</td>";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";




// ================================
echo "f) Display the order information for client_no ‘C00001’ and ‘C00002’.";
$query = "SELECT s_order_no,client_no,s_order_date from sales_order where client_no in('C00001','C00002');";

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


// ================================
echo "g) Find products whose selling price is greater than 2000 and less than or equal to 5000";
$query = "SELECT product_no,description,sell_price from product_master where sell_price >2000 and sell_price<=5000 ;";

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

// ================================
echo "h) Find products whose selling price is more than 1500. Calculate a new selling price as, original selling price * .15. Rename the new column in the
above query as new_price";

$query = "SELECT product_no,description,sell_price,sell_price * 15  \"NEW_PRICE\" from product_master where sell_price >1500";

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

// ================================
echo "i) List the names, city and state of clients who r not in the state of ‘Maharastra’";

$query = "SELECT name,city,state from client_master where state <> 'Maharashtra' ;";

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



// ================================
echo "j) Count the total number of orders";

$query = "SELECT s_order_no from sales_order_details";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		echo "<tr>";
		echo "<td>" . mysqli_num_rows($result) . "</td>";
		echo "</td></tr>";
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";



// ================================
echo "k) Calculate the average price of all the products.";

$query = "SELECT avg(cost_price) FROM product_master;";

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


// ================================
echo "l) Determine the maximum and minimum product prices.";

$query1 = "SELECT min(cost_price) FROM product_master;";
$query2 = "SELECT max(cost_price) FROM product_master;";

$result1 = mysqli_query($conn, $query1);
$result2 = mysqli_query($conn, $query2);

if($result1) {
	if($result2){
		echo "<table border= 1>";
		if(mysqli_num_rows($result1)){
			$fetch1 = mysqli_fetch_row($result1);
			$fetch2 = mysqli_fetch_row($result2);
				echo "<tr>";
				echo "<td>Min: " . $fetch1[0] . "</td>";
				echo "<td>Max: " . $fetch2[0] . "</td>";
				echo "</td></tr>";
			echo "</table>";
		} else {
			echo "<br><b>No records found</b><br>";
		}
	}else {
		echo "<br>FAILURE -> " . $query2;
	}
} else {
	echo "<br>FAILURE -> " . $query1;
} echo "<br>";



// ================================
echo "m) Count the number of products having price greater than or equal to 1500.";
$query = "SELECT product_no,description,sell_price from product_master where cost_price > 1500;";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
			echo "<tr>";
			echo "<td>" . mysqli_num_rows($result) . "</td>";
			echo "</td></tr>";
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";



// ================================
echo "n) Find all the products whose qty_on_hand is less than recorder level.";
$query = "SELECT product_no, description, qty_on_hand, recorder_lvl from product_master where qty_on_hand < recorder_lvl;";

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