
<!-- ========================================================================== -->
<!-- Q. 7 -->



<meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
<link rel="stylesheet" type="text/css" href="css.css">
<pre style="color: red">
	JUST TO QUOTE AND POINT THIS OUT:

	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	3. if you're using fseek() to write data to a file, remember to open the file in "r+"
	mode, example:

	$fp=fopen($filename,"r+");

	DON'T open the file in mode "a" (for append), because it puts
	the file pointer at the end of the file and doesn't let you
	fseek earlier positions in the file (it didn't for me!). Also,
	don't open the file in mode "w" -- although this puts you at
	the beginning of the file -- because it wipes out all data in
	the file.

	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	Took me half a day to figure :/
</pre>
<?php

	$file = 'files/7.txt';
	
	$fReadHandle = fopen("files/7.txt", 'r+');
	
	$currentPosition = fgets($fReadHandle, 4); // Reading from Start
	echo "<br> Reading from Start <br>" . $currentPosition;
	
	$currentPosition = fgets($fReadHandle, 5); // Reading from the last read
	echo "<br> Reading from the last read <br>" . $currentPosition;

	fseek($fReadHandle, 0); //fseek
	
	$currentPosition = fgets($fReadHandle, 4);
	echo "<br> Again Reading from Start <br>" . $currentPosition; //Again Reading from 
	
	$ftell = ftell($fReadHandle); //fseek
	echo '<br> $ftell' . " $ftell ";

	// Use single quotes around variables to prevent shell expansion
	echo "<br>Use single quotes around variables to prevent shell expansion";
	echo '<br>' . '\'ftell\'' . ' writes the word -> $ftell';
	echo "<br>" . "\"ftell\"" . ' writes value i.e -> ' . "$ftell";

?>



<!-- ========================================================================== -->


