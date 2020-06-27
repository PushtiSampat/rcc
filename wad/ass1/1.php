<link rel="stylesheet" type="text/css" href="css.css">
<meta name="viewport" content="width=device-width, initial-scale=1.0,shrink-to-fit=no">
<center>
	<form method="POST" name="form1">
		<table border="1" style="border: solid 3px #808080;">
			<tr>
				<td>Enter Amount </td>
				<td><input type="number" name="p"></td>
			</tr>

			<tr>
				<td>Enter Rate of Interest </td>
				<td><input type="number" name="r"></td>
			</tr>

			<tr>
				<td>Enter Number of years </td>
				<td><input type="number" name="n"></td>
			</tr>

			<tr>
				<td> <button class="rst"> Reset </button> </td>
				<td> <button class="sbt" name="sbt"> Submit </button> </td>
			</tr>
		</table>
	</form>
</center>
<?php
if(isset($_POST['sbt'])){
	echo "<center>";	
	$ans = ($_POST['p'] * $_POST['r'] * $_POST['n']) / 100;
	echo "$ans";
	echo "</center>";
}

?>