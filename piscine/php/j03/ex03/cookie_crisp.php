<?PHP
	$action = $_GET["action"];
	$name = $_GET["name"];
	$value = $_GET["value"];

	function set_cookie($name, $value)
		setcookie($name, $value, time() +3600);

	function get_cookie($name, $value)
	{
		if (isset(_COOKIE[$name]))
			echo _COOKIE[$name] . "\n";

	}

	function del_cookie($name, $value)
		setcookie($name, NULL);

	$my_tab = array
	( 	"set" => "set_cookie",
		"get" => "get_cookie",
		"del" => "del_cookie");
	$value_array = $my_tab[$action];
	if ($value_array)
		$value_array($name, $value_array);
?>
