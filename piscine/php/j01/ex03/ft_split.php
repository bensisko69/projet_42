<?PHP
function ft_split($my_str)
{
	$my_tab	= preg_split("/[\s]+/", $my_str);
	sort($my_tab);
	return $my_tab;
}
?>