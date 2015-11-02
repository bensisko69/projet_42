#!/usr/bin/PHP
<?PHP
	$my_str = trim(preg_replace("/[\s\t]+/", ' ', $argv[1]));
	echo "$my_str\n";
?>