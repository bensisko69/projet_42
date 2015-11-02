<?php
	Class Color 
	{
		public static $verbose = False;
		public $red = 0;
		public $green = 0;
		public $blue = 0;
		function __construct(array $kwargs)
		{
			if (array_key_exists('rgb', $kwargs))
			{
				$this->red = intval($kwargs['rgb']) / 65536 % 256;
				$this->green = intval($kwargs['rgb']) / 256 % 256;
				$this->blue = intval($kwargs['rgb']) % 256;
			}
			else
			{
				if (array_key_exists('red', $kwargs))
					$this->red = intval($kwargs['red']);
				else
					$this->red = 0;
				if (array_key_exists('green', $kwargs))
					$this->green = intval($kwargs['green']);
				else
					$this->green = 0;
				if (array_key_exists('blue', $kwargs)) 
					$this->blue = intval($kwargs['blue']);
				else
					$this->blue = 0;
			}
			
			if (self::$verbose == True)
				print($this .' constructed.' . PHP_EOL);
		}

		static function doc()
		{
			return file_get_contents("Color.doc.txt");
		}

		function __destruct()
		{
			if (self::$verbose == True)
				print($this .' destructed.' . PHP_EOL);
			return ;
		}

		function add(Color $color)
		{
			$new_color = array('red' => $this->red + $color->red, 
								'green' => $this->green + $color->green, 
								'blue' => $this->blue + $color->blue);
			return new Color ($new_color);
		}

		function sub(Color $color)
		{
			$new_color = array('red' => $this->red - $color->red, 
								'green' => $this->green - $color->green, 
								'blue' => $this->blue - $color->blue);
			return new Color ($new_color);
		}

		function mult($facteur)
		{
			$new_color = array('red' => $this->red * $facteur, 
								'green' => $this->green * $facteur, 
								'blue' => $this->blue * $facteur);
			return new Color ($new_color);
		}

		function __toString()
		{
			return 'Color( red: '.$this->red.', green: '.$this->green.', blue: '.$this->blue.' )';
		}
	}

?>