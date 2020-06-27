
<!-- ========================================================================== -->
<!-- Q. 2 -->



<link rel="stylesheet" type="text/css" href="css.css">
<meta name="viewport" content="width=device-width, initial-scale=1.0,shrink-to-fit=no">
<center>
	<form name="form1" action="<?php $_PHP_SELF ?>">
		<table border="1" style="border: solid 3px #808080;">
			<tr>
				<td>First Name </td>
				<td><input type="text" name="fname" autocomplete="off"></td>
			</tr>

			<tr>
				<td>Last Name </td>
				<td><input type="text" name="lname" autocomplete="off"></td>
			</tr>

			<tr>
				<td colspan=2 style="text-align: center;"> <button class="sbt" name="sbt"> Submit </button> </td>
			</tr>
		</table>
	</form>
</center>

<?php
// https://stackoverflow.com/questions/1372147/check-whether-a-request-is-get-or-post
echo "<br>Checking if get or post";
if($_SERVER['REQUEST_METHOD'] === 'POST') {
	echo "<br>Method is Post";
	if($_POST['fname']) {
		echo "<br> Your First name is" . $_POST['fname'];
	}
	if($_POST['lname']) {
		echo "<br> Your Last name is" . $_POST['lname'];
	}
}


else if ($_SERVER['REQUEST_METHOD'] === 'GET') {
	echo "<br>Method is Get";
	if($_GET['fname']) {
		echo "<br> Your First name is: " . $_GET['fname'];
	}
	if($_GET['lname']) {
		echo "<br> Your Last name is: " . $_GET['lname'];
	}	
}

// Request
if($_REQUEST['fname']) {
	echo "<br> Your First name is: " . $_REQUEST['fname'];
}
if($_REQUEST['fname']) {
	echo "<br> Your First name is: " . $_REQUEST['lname'];
}


?>


<!-- ========================================================================== -->


