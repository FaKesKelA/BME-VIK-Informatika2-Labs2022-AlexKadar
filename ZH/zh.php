<html>
<head>
	<title>ZH</title>
</head>
<body>
<h1>Név: Kádár Alex, NEPTUN: JWX86H</h1>
<table border=1>
	<tr style="background-color:lightblue;"><th>Épület</th><th>Termek száma</th><th>Össz férőhely</th></tr>
	<?php
		 if(!isset($_GET["Nmin"])){
		 	die("nincs ferohely");
		 }
		 $link = mysqli_connect("localhost", "root", "", "zh") 
		             or die("Kapcsolódási hiba: " . mysqli_error());

		 $escaped_nmin = mysqli_real_escape_string($link, $_GET["Nmin"]);

		 $query = "SELECT epulet, COUNT(epulet) AS terem_szam, SUM(ferohely) AS fer_szam FROM terem GROUP BY epulet HAVING fer_szam >= '{$escaped_nmin}' ORDER BY epulet";
		 $result = mysqli_query($link, $query) or die(mysqli_error($link));

		 for($i =0; $row = mysqli_fetch_assoc($result); $i++) {
		 	$background = ($i % 2 == 0) ? '' : "style='background-color:lightblue' ";
		     echo "<tr $background><td>".$row["epulet"]."</td><td>".$row["terem_szam"]."</td><td>".$row["fer_szam"]."</td></tr>";
		 }
		 mysqli_free_result($result);
		 mysqli_close($link);

	?>
</table>
</body>
</html>