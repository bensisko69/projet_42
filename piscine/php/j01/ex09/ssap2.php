#!/usr/bin/PHP
<?PHP
	$my_array = Array();
	$my_array_alpha = Array();
	$my_array_nbr = Array();
	$my_array_other = Array();

	for ($i=1; $i < $argc; $i++) 
		$my_array = array_merge(preg_split("/[\s]+/", $argv[$i]), $my_array);
	$len = count($my_array);
	for ($i = 0; $i < $len; $i++)
	{
		if (ctype_digit($my_array[$i]))
		{
			$my_array_nbr[$a] = $my_array[$i];
			$a++;
		}
		else if (ctype_alpha($my_array[$i]))
		{
			$my_array_alpha[$b] = $my_array[$i];
			$b++;
		}
		else if (ctype_print($my_array[$i]))
		{
			$my_array_other[$c] = $my_array[$i];
			$c++;
		}
	}
	sort($my_array_nbr);
	sort($my_array_alpha);
	sort($my_array_other);
	foreach ($my_array_alpha as $value)
		 	echo "$value\n";
	foreach ($my_array_nbr as $value)
		 	echo "$value\n";
	foreach ($my_array_other as $value)
		 	echo "$value\n";
?>