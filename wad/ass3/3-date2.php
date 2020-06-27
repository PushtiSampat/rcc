<?php
require_once ('config.php');
echo strtotime("now");
echo strtotime("20-jan-1996") . "<br>";

echo date('Y-m-d', strtotime("20-jan-1996")) . "<br>";
echo ">" . date('Y-M-d', strtotime("20-jan-1996")) . "<br>";



 
// dayss(one additional s) adds one additional day


// This code adds the date with the current date in php

1. echo date('d-m-y', strtotime("+1 day")) . "<br>"; // 17-04-20
2. echo date('d-m-y', strtotime("+1 days")) . "<br>"; // 17-04-20
3. echo date('d-m-y', strtotime("+1 dayss")) . "<br>"; // 18-04-20

// See the 3 rd line, when I add one additional s, one additional day is incremented
// How is this possible ?

echo "INSERT into sales_order values('O1111','1996-01-12','C00001','','S00001','F','N','1996-01-20','IP')";

?>