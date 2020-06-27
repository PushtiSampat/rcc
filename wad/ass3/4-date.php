<!-- https://www.guru99.com/php-date-functions.html -->

<?php
require_once ('config.php');
// echo strtotime("now");

// ============================================================================
echo "a) Display the order number and day on which clients placed their order.";
$query = "SELECT s_order_no, s_order_date from sales_order";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . date('D', strtotime($fetch[1])) . "</td>";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";



// ============================================================================
echo "b) Display the month (in alphabets) and date when the order must be delivered.";
$query = "SELECT dely_date from sales_order";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . date('M', strtotime($fetch[0])) . "</td>";
			echo "<td>" . $fetch[0] . "</td>";
			echo "<td>" . date('F', strtotime($fetch[0])) . "</td>";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";


// ============================================================================
echo "c) Display the order_date in the format ‘DD-Month-yy’. e.g. 12-February-96.";
$query = "SELECT s_order_date from sales_order";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {
			echo "<tr>";
			echo "<td>" . date('d-F-y', strtotime($fetch[0])) . "</td>";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";



// ============================================================================
echo "d) Find the date, 15 days after today’s date";
echo "<table border= 1>";
echo "<tr><td>";
echo date('d-M-Y', strtotime("+15 days")) . "<br>"; // 18-04-20
echo "</td></tr>";
echo "</table>";


// ============================================================================
echo "e) Find the number of days elapsed between today’s date and the delivery date of the orders placed by the clients.";
$query = "SELECT dely_date from sales_order";

$result = mysqli_query($conn, $query);

if($result) {
	echo "<table border= 1>";
	if(mysqli_num_rows($result)){
		while($fetch = mysqli_fetch_array($result)) {

			$date1 = date_create($fetch[0]);
			$date2 = date_create("now");
			
			$diff = date_diff($date2, $date1);
			
			echo "<tr>";
			echo "<td>" . $diff->format('%R %a days') . "</td>";
			echo "</td></tr>";
		}
		echo "</table>";
	} else {
		echo "<br><b>No records found</b><br>";
	}
} else {
	echo "<br>FAILURE -> " . $query;
} echo "<br>";


// ============================================================================

?>