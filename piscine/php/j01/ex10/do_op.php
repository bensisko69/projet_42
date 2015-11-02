#!/usr/bin/php
<?PHP
	$my_nbr1 = trim($argv[1]);
	$my_ope = trim($argv[2]);
	$my_nbr2 = trim($argv[3]);

	if ($argc != 4)
	{
		echo "Incorrect Parameters\n";
		exit();
	}
	if ($my_ope == '-')
		$result = $my_nbr1 - $my_nbr2;
	if ($my_ope == '+')
		$result = $my_nbr1 + $my_nbr2;
	if ($my_ope == '*')
		$result = $my_nbr1 * $my_nbr2;
	if ($my_ope == '/')
		$result = $my_nbr1 / $my_nbr2;
	if ($my_ope == '%')
		$result = $my_nbr1 % $my_nbr2;
	echo "$result\n";
?>