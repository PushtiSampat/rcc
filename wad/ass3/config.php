<meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
<link rel="stylesheet" type="text/css" href="css.css">

<?php

$servername = "localhost";
$username =  "root";
$password = "";
$database = "rcc-ass3";


$conn = mysqli_connect($servername, $username, $password, $database);
if($conn->connect_error) {
	die();
} else { 
	// echo "Connection Established Successfully";
};

?>