#!/usr/bin/PHP
<?PHP
	$new_array = Array();
	$my_array = preg_split("/[\s]+/", $argv[1]);
	$len = count($my_array);

	for ($i=1; $i < $len; $i++)
		array_push($new_array, $my_array[$i]);
	array_push($new_array, $my_array[0]);
	echo implode(' ', $new_array);
	echo "\n";
?>