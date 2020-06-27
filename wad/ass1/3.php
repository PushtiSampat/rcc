<link rel="stylesheet" type="text/css" href="css.css">
<meta name="viewport" content="width=device-width, initial-scale=1.0,shrink-to-fit=no">
<center>
	<form name="form1" method="GET" action="<?php $_PHP_SELF ?>">
		<table border="1" style="border: solid 3px #808080;">
			<tr>
				<td>Start </td>
				<td><input type="text" name="minRad" autocomplete="off"></td>
			</tr>

			<tr>
				<td>End </td>
				<td><input type="text" name="maxRad" autocomplete="off"></td>
			</tr>

			<tr>
				<td colspan=2 style="text-align: center;"> <button class="sbt" name="sbt"> Submit </button> </td>
			</tr>
		</table>
	</form>
</center>

<?php
// $_GET['minRad'] = 1;
// $_GET['maxRad'] = 1;


if (isset($_GET['sbt'])) {
	$start = $_GET['minRad'];
	$end = $_GET['maxRad'];	
	if($start < 1) {
		echo "<br>Minimum Value must be 1 or greater";
		die();
	}	
	else if($start > $end){
		echo "<br>Max value cannot be greater than min value";
		die();
	}

	for ($i = $start; $i <= $end ; $i++) { 
		echo "<br> The radius of " .$i. " is " . (3.14 * $i * $i);
	}
}

?>