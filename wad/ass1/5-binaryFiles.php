
<!-- ========================================================================== -->
<!-- Q. 5 -->



<!-- https://www.worldbestlearningcenter.com/index_files/php-file-input-output.htm -->

<link rel="stylesheet" type="text/css" href="css.css">
<meta name="viewport" content="width=device-width, initial-scale=1.0,shrink-to-fit=no">
<center>
	<form method="POST" name="form1">
		<table border="1" style="border: solid 3px #808080;">
			<tr>
				<td>Name </td>
				<td><input type="text" name="sname" required autocomplete="off"></td>
			</tr>
			<tr>
				<td colspan="2" class="text-center"> <button class="sbt" name="sbt"> Submit </button></td>
			</tr>
		</table>
	</form>
</center>
<?php
if(isset($_POST['sbt'])) {
	if ($_POST['sname'] == '') { echo "Form not submitted. Name not valid"; } 
	else {
		$f1 = @fopen('files/studinfo.txt', 'a+b');
		$sname = "\r\n" . $_POST['sname'];
		$fwrite = fwrite($f1, $sname);

		// fwrite() returns the number of bytes written, or FALSE on error.
		if($fwrite === false) {
			echo "Form not submitted."; 
		} else {
			echo "Form Submitted Successfully. " . $fwrite . " bytes written.";
		}
		fclose($f1); 
	} 
}
?>



<!-- ========================================================================== -->

