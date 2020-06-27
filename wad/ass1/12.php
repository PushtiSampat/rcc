<link rel="stylesheet" type="text/css" href="css.css">
<?php
$type = array('Clb', 'Hrt', 'Diam', 'Spd');
$rank = array('1', '2','3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A');

echo "<div style = 'display: inline-flex;'>";

echo "Ascending: <br>";
$i = '';
foreach ($type as $k1) {
	echo "<div>";
	foreach ($rank as $k2) {
		if($k1 == 'Clb' || $k1 == 'Spd') {
			echo "<b>" .$i . "</b>" . $k1 . "&nbsp;(" . $k2 . ")<br>";
		} else {
			echo "<font color='red'>";
			echo "<b>". $i . "</b>" . $k1 . "&nbsp;(" . $k2 . ")<br>";
			echo "</font>";
		}
	}
	echo "</div>";
}

echo "<span style = 'margin-left: 45px;'></span>";

echo "Descending: <br>";
foreach (array_reverse($type) as $k1) {
	echo "<div>";
	foreach (array_reverse($rank) as $k2) {
		if($k1 == 'Clubs' || $k1 == 'Spades') {
			echo $k1 . "&nbsp;(" . $k2 . ")<br>";
		} else {
			echo "<font color='red'>";
			echo $k1 . "&nbsp;(" . $k2 . ")<br>";
			echo "</font>";
		}
	}
	echo "</div>";
}

echo "<span style = 'margin-left: 45px;'></span>";

echo "Shuffled: <br>";

$numbers = range(1, 52);
$shuffle = shuffle($numbers);

$i = 0;
echo '<table border="1" style="border: solid 3px #808080;">';
echo "<tr>";
foreach ($numbers as $key) {
	$rem = $key % 4; 
	$div = $key % 13;
	echo "<td>";
	if($rem == 0 || $rem == 3) {
		echo $rank[$div] . " of " . $type[$rem] . " ";
	} else {
		echo "<font color= 'red'>";
		echo $rank[$div] . " of " . $type[$rem] . " ";
		echo "</font>";
	}
	echo "</td>";
	$i++;
	if($i % 4 == 0) {
		echo "</tr>";
		echo "<tr>";
	}
}

echo "</div>";
?>