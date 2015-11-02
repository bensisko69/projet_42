<?PHP
	function ft_is_sort($array)
	{
		$c_array = $array;
		$d_array = $array;

		sort($c_array);
		rsort($d_array);
		if ($c_array == $array || $d_array == $array)
			return true;
		else
			return false;
	}
?>