#!/usr/bin/PHP
<?PHP
	while (1)
	{
		echo "Entrez un nombre : ";
		$value = trim(fgets(STDIN));
		if (is_numeric($value) == TRUE) 
		{
			if ($value %2 == 0)
				echo "Le chiffre $value est pair\n";
			else if ($value %2 == 1)
				echo "Le chiffre $value est impair\n";
		}
		else if (feof(STDIN))
		{ 
			echo "\n";
			exit(42);
		}
		else
			echo "'$value' n'est pas un chiffre\n";
	}
?>