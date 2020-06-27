<!-- ========================================================================== -->
<!-- Q. 15 (Part2)-->


<meta name="viewport" content="width=device-width, initail-scale=1.0, shrink-to-fit=no">
<link rel="stylesheet" type="text/css" href="css.css">
 
<br>
<?php

$arr1 = $arr2 = $arr3 = array("Pic1","pic2","pic10","pic01","pic100","pic20","pic30","pic200");

usort($arr1, "strcmp");
usort($arr2, "strnatcmp");
usort($arr3, "strnatcasecmp");

echo "<div style='display: inline-flex;'>";

echo "<pre>strcmp<br><br>"; var_dump($arr1); echo "</pre>";
echo "<pre>strnatcmp<br><br>"; var_dump($arr2); echo "</pre>";
echo "<pre>strnatcasecmp<br><br>"; var_dump($arr3); echo "</pre>";

echo "</div>";

?>


<!-- ========================================================================== -->

