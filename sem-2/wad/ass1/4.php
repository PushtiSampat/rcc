
<!-- ========================================================================== -->
<!-- Q. 4 -->



<link rel="stylesheet" type="text/css" href="css.css">
<meta name="viewport" content="width=device-width, initial-scale=1.0,shrink-to-fit=no">
<center>
	<form method="POST" name="form1">
		<table border="1" style="border: solid 3px #808080;">
			<tr>
				<td>Student ID </td>
				<td><input type="number" name="sid" required></td>
			</tr>

			<tr>
				<td>Name </td>
				<td><input type="text" name="sname" required></td>
			</tr>

			<tr>
				<td> Subject 1 </td>
				<td onmouseup="updateResult();"><input type="number" name="m1" min="0" max="100" value="0" onkeyup="updateResult();" required></td>
			</tr>

			<tr>
				<td> Subject 2 </td>
				<td onmouseup="updateResult();"><input type="number" name="m2" min="0" max="100" value="0" onkeyup="updateResult();" required></td>
			</tr>

			<tr>
				<td> Subject 3 </td>
				<td onmouseup="updateResult();"><input type="number" name="m3" min="0" max="100" value="0" onkeyup="updateResult();" required></td>
			</tr>

			<tr>
				<td> <button class="rst"> Reset </button> </td>
				<td> <button class="sbt" name="sbt"> Submit </button></td>
			</tr>
			<tr>
				<td> <p>Total</p> </td>
				<td> <p id="total">0</p> </td>
			</tr>

			<tr>
				<td> <p>Percentage</p> </td>
				<td> <p id="per">0</p> </td>
			</tr>
		</table>
	</form>
</center>
<script type="text/javascript">
	function updateResult() {
		var m1 = parseFloat(document.form1.m1.value);
		var m2 = parseFloat(document.form1.m2.value);
		var m3 = parseFloat(document.form1.m3.value);
		var total = m1 + m2 + m3;
		if(isNaN(total)) {
			document.getElementById('total').innerHTML = "Enter marks of all Subjects";
			document.getElementById('per').innerHTML = "Enter marks of  all Subjects";
		}
		else {
			document.getElementById('total').innerHTML = total;
			document.getElementById('per').innerHTML = total / 3;
		}
	}
</script>
<?php
if(isset($_POST['sbt'])){
	if($_POST['sid'] == '' || is_nan($_POST['sid'])) {
		echo "Form not submitted. ID not valid";
	}
	else if ($_POST['sname'] == '') {
		echo "Form not submitted. Name not valid";
	}

	else {
		$m1 = $_POST['m1'];
		$m2 = $_POST['m2'];
		$m3 = $_POST['m3'];
		if($m1 < 0 || $m1 > 100) {
			echo "<br>Form not submitted. Marks of subject 1 is invalid";
		} else if($m2 < 0 || $m2 > 100) {
			echo "<br>Form not submitted. Marks of subject 2 is invalid";
		} else if($m3 < 0 || $m3 > 100) {
			echo "<br>Form not submitted. Marks of subject 3 is invalid";
		} else {
			echo "<br>Form Submitted Successfully.";
			$tot = $m1 + $m2 + $m3;
			$per = $tot / 3;
			echo "<br>Tot: " . number_format((float)$tot, 2, '.', ',');
			echo "<br>Per: " . number_format((float)$per, 2, '_', '');
			// Parameters:

			// number
			// The number being formatted.

			// decimals
			// Sets the number of decimal points.

			// dec_point
			// Sets the separator for the decimal point.

			// thousands_sep
			// Sets the thousands separator.

			switch(1) {
				case ($per > 70): echo "<br>Grade A"; break;
				case ($per > 65): echo "<br>Grade B"; break;
				case ($per > 60): echo "<br>Grade C"; break;
				case ($per > 55): echo "<br>Grade D"; break;
				case ($per > 50): echo "<br>Grade E"; break;
				default: echo "<br>Grade F"; break;
			}
		}
	}
}
?>



<!-- ========================================================================== -->


