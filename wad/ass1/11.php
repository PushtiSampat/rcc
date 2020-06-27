<link rel="stylesheet" type="text/css" href="css.css">
<form name="form1" method="post">
<center>
  <table border = 1>
    <tr>
      <td>First city</td>
      <td>Second city</td>
    </tr>

    <tr>
      <td>
        <select name = "cityA">
          <option value = 0>Kachchh</option>
          <option value = 1>Rajkot</option>
          <option value = 2>Ahmedabad</option>
          <option value = 3>Surat</option>
          <option value = 4>Mumbai</option>
        </select>
      </td>

      <td>
        <select name = "cityB">
          <option value = 0>Kachchh</option>
          <option value = 1>Rajkot</option>
          <option value = 2>Ahmedabada</option>
          <option value = 3>Surat</option>
          <option value = 4>Mumbai</option>
        </select>
      </td>
    </tr>

    <tr class="text-center">
      <td colspan = 2>
        <input type = "submit" value = "Calculate Distance" class=" sbt" style="padding: 10px;" name="sbt">
      </td>
    </tr>
  </table>
</center>
</form>
<?php

if(isset($_POST['sbt'])) {
  $cityA = $_POST['cityA'];
  $cityB = $_POST['cityB'];
  echo "$cityA $cityB";
  $city = array (
    "Kachchh",
    "Rajkot",
    "Ahmedabad",
    "Surat",
    "Mumbai",
  );

  $distance = array (
    array (000, 280, 395, 655, 999),
    array (280, 000, 115, 415, 800),
    array (395, 115, 000, 302, 650),
    array (655, 415, 302, 000, 200),
    array (999, 800, 650, 200, 000)
  );

  $result = $distance[$cityA][$cityB];
  print "<h3>The distance between ";
  print "$city[$cityA] and $city[$cityB]";
  print " is $result miles.</h3>";
}
?>