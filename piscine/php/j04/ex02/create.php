<?php
	if ($_POST['submit'] == 'OK')
	{
		if (!file_exists("../private"))
		{
			mkdir("../private");
		}
		if (!file_exists("../private/passwd"))
		{
			$passwd_hash = hash("whirlpool", $_POST["passwd"]);
			$user = array(login => $_POST["login"], passwd => $passwd_hash);
			$super_tab = array($user);
			$serialized = serialize($super_tab);
			file_put_contents("../private/passwd", $serialized);
			echo "OK\n";
		}
		else
		{
			$serialized = file_get_contents("../private/passwd");
			$super_tab = unserialize($serialized);
			$i = 0;
			$flag = 0;
			foreach ($super_tab as $user) 
			{
				 if ($user['login'] == $_POST['login'])
				 {
				 	echo "ERROR\n";
				 	$flag = 1;
				 }
				 $i++;
			}
			if ($flag == 0)
			{
				$passwd_hash = hash("whirlpool", $_POST["passwd"]);
				$user = array(login => $_POST["login"], passwd => $passwd_hash);
				$super_tab[$i] = $user;
				$serialized = serialize($super_tab);
				file_put_contents("../private/passwd", $serialized);
				echo "OK\n";
			}
		}
	}
	else
		echo "ERROR\n";
?>