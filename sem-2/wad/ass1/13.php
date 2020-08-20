
<!-- ========================================================================== -->
<!-- Q. 13 -->


<meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
<link rel="stylesheet" type="text/css" href="css.css">
<?php

$i = 0;

if(file_exists("files/studinfo.txt")) {
	$f1Handle = @fopen("files/studinfo.txt", "rb");
	
	$fn = fopen("files/studinfo.txt","r");
	while(! feof($fn))  {
		$array[$i++] = fgets($fn);
	}
	fclose($fn);
	echo "<br>
	// By this way, last inserted will be first diplayed<br>
	// use for loop for reversed
	";
	echo '<table border="1" style="border: solid 3px #808080;">';
	while($i--) {
		echo "<tr>";
		echo "<td>";
		echo $array[$i];
		echo "</td>";
		echo "</tr>";
	}
	echo "</table>";

	fclose($f1Handle);

} else {
	echo "No such File Exists";
}
?>

<!-- ========================================================================== -->

