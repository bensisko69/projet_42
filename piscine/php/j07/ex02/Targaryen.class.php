<?php
	class Targaryen
	{
		function getBurned()
		{
			if ($this->resistsFire() == True)
				return "emerges naked but unharmed";
			else
				return "burns alive";
		}

		function resistsFire()
		{
			return False;
		}
	}
?>