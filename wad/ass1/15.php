<meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
<link rel="stylesheet" type="text/css" href="css.css">
<?php

$str = "*** Lorem Ipsum ***";
echo "<center>";
echo "<h2>$str</h2>";
echo '<table border="1" style="border: solid 5px #f1e9e9; border-radius: 1rem;">';

echo "<tr><td>";
echo "trim ";
echo "</td><td>";
echo trim($str,"***"); 
echo "</td></tr>";

echo "<tr><td>";
echo "rtrim ";
echo "</td><td>";
echo rtrim($str,"***"); 
echo "</td></tr>";

echo "<tr><td>";
echo "ltrim ";
echo "</td><td>";
echo ltrim($str,"***"); 
echo "</td></tr>";

echo "<tr><td>";
echo "STR_PAD_LEFT ";
echo "</td><td>";
echo str_pad($str, 25, "_", STR_PAD_LEFT); 
echo "</td></tr>";

echo "<tr><td>";
echo "STR_PAD_BOTH ";
echo "</td><td>";
echo str_pad($str, 25, "_", STR_PAD_BOTH); 
echo "</td></tr>";

echo "<tr><td>";
echo "STR_PAD";
echo "</td><td>";
echo str_pad($str, 25, "_"); 
echo "</td></tr>";

echo "<tr><td>";
echo "lcfirst(Lower case)";
echo "</td><td>"; 
echo lcfirst("Hello world!");
echo "</td></tr>";

echo "<tr><td>";
echo "ucfirst(Upper case)";
echo "</td><td>"; 
echo ucfirst("hello world!");
echo "</td></tr>";

echo "<tr><td>";
echo "ucwords";
echo "</td><td>"; 
echo ucwords("hello world");
echo "</td></tr>";


echo "<tr><td>";
echo "Strtolower";
echo "</td><td>"; 
echo Strtolower($str);
echo "</td></tr>";


echo "<tr><td>";
echo "strtoupper";
echo "</td><td>"; 
echo strtoupper($str);
echo "</td></tr>";


echo "<tr><td>";
echo "strrev";
echo "</td><td>"; 
echo strrev($str);
echo "</td></tr>";

echo "<tr><td>";
echo "str_shuffle (ymmv)";
echo "</td><td>"; 
echo str_shuffle($str);
echo "</td></tr>";

echo "<tr><td>";
echo "str_repeat";
echo "</td><td>"; 
echo str_repeat("ADJP ", 5);
echo "</td></tr>";

$str2 = "Lorem Ipsum Dolor Set Amet";
echo "<tr><td>";
echo "explode";
echo "</td><td>"; 
print_r(explode(' ', $str2, -1));
echo "</td></tr>";

$arr = array('Lorem','Ipsum!','Set','Amet!');
echo "<tr><td>";
echo "implode";
echo "</td><td>"; 
echo implode("<b>+</b>", $arr);
echo "</td></tr>";

echo "<tr><td>";
echo "strcmp";
echo "</td><td>"; 
echo strcmp("Ajinkya","ajinkya");
echo "</td></tr>";

echo "<tr><td>";
echo "strcasecmp";
echo "</td><td>"; 
echo strcasecmp("Ajinkya","ajinkya");
echo "</td></tr>";

echo "<tr><td>";
echo "strlen";
echo "</td><td>"; 
echo strlen("Ajinkya");
echo "</td></tr>";

echo "<tr><td>";
echo "strstr";
echo "</td><td>"; 
echo strstr("rajinkya26@gmail.com", "@");
echo "</td></tr>";

echo "<tr><td>";
echo "stristr";
echo "</td><td>"; 
echo stristr("rajinkya26@gmail.com", "@G");
echo "</td></tr>";

echo "<tr><td>";
echo "strrstr(true)";
echo "</td><td>"; 
echo strchr("Hello world world!","world",true);
echo "</td></tr>";

echo "<tr><td>";
echo "strchr";
echo "</td><td>"; 
echo strchr("Hello world world!","world");
echo "</td></tr>";

echo "<tr><td>";
echo "strrchr";
echo "</td><td>"; 
echo strrchr("Hello world world!","world");
echo "</td></tr>";


echo "<tr><td>";
echo "strpos";
echo "</td><td>"; 
echo strpos("Ajinkya php, php","php");
echo "</td></tr>";

echo "<tr><td>";
echo "strrpos";
echo "</td><td>"; 
echo strrpos("Ajinkya php, php","php") . "<br>";
echo "</td></tr>";


echo "<tr><td>";
echo "substr_replace";
echo "</td><td>"; 
echo substr_replace("Bobby", 'bob', 0) . "<br>";
echo "</td></tr>";


$letters = array('a', 'p');
$fruit   = array('apple', 'pear');
$text    = 'a p';
$output  = str_replace($letters, $fruit, $text);

echo "<tr><td>";
echo "str_replace";
echo "</td><td>"; 
echo $output . "<br>";
echo "</td></tr>";

echo "</table>";
echo "</center>";

// echo "<b> </b>" . . "<br>";
// echo "<b> </b>" . . "<br>";
?>