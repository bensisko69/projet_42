<?php
	class Tyrion extends Lannister
	{
		function sleepWith($who)
		{
			parent::sleepWith($who);
			if ($who instanceof Lannister)
				print("Not even if I'm drunk !\n");
		}
	}
?>