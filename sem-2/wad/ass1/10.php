
<!-- ========================================================================== -->
<!-- Q. 10 -->



<link rel="stylesheet" type="text/css" href="css.css">
<?php

$milk = array (
	array (
		"name" => "Shakti",
		"price" => 25
	),
	array (
		"name" => "Amul",
		"price" => 30
	),
	array (
		"name" => "Branded",
		"price" => 28
	)
);

$uasort = $usort = $milk;

echo "<div style = 'display: flex;'>";

// =================Displaying normal 2D array======================
echo "<div>";

echo "Normal Array<br><br>";
array_walk_recursive($milk, function ($item, $key) {
    echo "$key : $item<br>";
});

echo "</div>";


// =================== Sorting accorrding to price===========

usort($usort, function($a, $b) {
    return $a['price'] <=> $b['price']; // for descending, return $b['price'] <=> $a['price'];
});

echo "<div>";

//use uasort to preserve keys, use "print_r($uasort);" to check
uasort($uasort, function($a, $b) {
    return $a['price'] <=> $b['price'];
});

echo "Sort by price<br><br>";
array_walk_recursive($usort, function ($item, $key) {
	static $i = 1;
    echo " &nbsp; $key : $item | ";
    if(!($i++ % 2)) { //beacuse there are only 2 elements
    	echo "<br>";
    }
});

echo "</div>";



// ===========Sorting according to milk brand===========

echo "Sort by name<br><br>";
$milk2 = $milk;

usort($milk2, function($a, $b) {
	return $a['name'] <=> $b['name'];
});	


array_walk_recursive($milk2, function($item, $key) {
	static $i = 1;
    echo " &nbsp; $key : $item | ";
    if(!($i++ % 2)) { echo "<br>"; }
});


echo "</div>";


?>


<!-- ========================================================================== -->
