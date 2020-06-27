<link rel="stylesheet" type="text/css" href="css.css">
<meta name="viewport" content="width=device-width, initial-scale=1.0,shrink-to-fit=no">
<?php

$arr = array("1. Chole Bhature","2. Chana Masala","3. Dal Makhani","4. Aloo Paratha","5. Kadai Paneer");

$i = 2;

foreach ($arr as $value) {
	if($i % 2) {
		echo "<br>" . $value;
	}
	$i++;
} 
?>