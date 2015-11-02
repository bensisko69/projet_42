#!/usr/bin/PHP
<?php
	$my_array = Array();

	for ($i=1; $i < $argc; $i++) 
		$my_array = array_merge(preg_split("/[\s]+/", $argv[$i]), $my_array);
	sort($my_array);
	foreach ($my_array as $value)
		 	echo "$value\n";
?>