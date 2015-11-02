<?php
	class Jaime extends Lannister
	{
		function sleepWith($who)
		{
			parent::sleepWith($who);
			if ($who instanceof Cersei)
				print("With pleasure, but only in a tower in Winterfell, then.\n");
			else if ($who instanceof Lannister)
				print("Not even if I'm drunk !\n");
		}
	}
?>