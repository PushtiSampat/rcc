
<!-- ========================================================================== -->
<!-- Q. 8 -->



<meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
<link rel="stylesheet" type="text/css" href="css.css">


<h1>Hobbies</h1>

<form name="form1" method="POST">
  <input type="checkbox" id="h1" name="hobby[]" value="Dance"> Dance <br>
  <input type="checkbox" id="h2" name="hobby[]" value="Sing"> Singing <br>
  <input type="checkbox" id="h3" name="hobby[]" value="Study"> Study <br><br>
<input type="submit" class="sbt" value="Submit" name="sbt">
</form>

<?php
if(isset($_POST['sbt'])){

	if(!empty($_POST['hobby'])){
		foreach($_POST['hobby'] as $selected){
			echo $selected."</br>";
		}
	}
}
?>



<!-- ========================================================================== -->


