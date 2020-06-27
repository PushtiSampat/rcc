<meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
<link rel="stylesheet" type="text/css" href="css.css">
<?php
if(file_exists("files/studinfo.txt")) {
	$f1Handle = @fopen("files/studinfo.txt", "rb");
	echo fread($f1Handle, filesize('files/studinfo.txt'));
	
	// Line By Line Starts
	$fn = fopen("files/studinfo.txt","r");
	while(! feof($fn))  {
		$result = fgets($fn);
		echo "<br>" . $result;
	}
	fclose($fn);
	// Line By Line Ends

	fclose($f1Handle);

} else {
	echo "No such File Exists";
}
?>