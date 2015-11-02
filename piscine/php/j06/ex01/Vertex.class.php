<?php
	Class Vertex
	{
		public static $verbose = False;
		private $_x = 0;
		private $_y = 0;
		private $_z = 0;
		private $_w = 0;
		private $_Color = 0;

		public function getX(){return $this->$_x;}
		public function getY(){return $this->$_y;}
		public function getZ(){return $this->$_z;}
		public function getW(){return $this->$_w;}
		public function getColor(){return $this->$_Color;}

		static function doc()
		{
			return file_get_contents("Vertex.doc.txt");
		}

		function __construct(array $kwargs)
		{
			if (array_key_exists('x', $kwargs))
				$this->_x = $kwargs['x'];

			if (array_key_exists('y', $kwargs))
				$this->_y = $kwargs['y'];

			if (array_key_exists('z', $kwargs))
				$this->_z = $kwargs['z'];
		
			if (array_key_exists('w', $kwargs)) 
				$this->_w = $kwargs['w'];
			else
				$this->_w = 1.0;

			if (array_key_exists('color', $kwargs))
				$this->_Color = $kwargs['color'];
			else
				$this->_Color = new Color( array( 'red' => 255, 'green' =>   255, 'blue' =>   255 ) );

			if (self::$verbose == True)
				print($this .' constructed.' . PHP_EOL);

			return;
		}

		function __destruct()
		{
			if (self::$verbose == True)
				print($this .' destructed.' . PHP_EOL);

			return;
		}

		function __toString()
		{
			if (self::$verbose == True)
				return 'Vertex( x: '. number_format($this->_x, 2, '.', '') .', y: '. number_format($this->_y, 2, '.', '') .', z:'. number_format($this->_z, 2, '.', '') .', w:'. number_format($this->_w, 2, '.', '') .') ,' .$this->_Color;
			else 
				return 'Vertex( x: '. number_format($this->_x, 2, '.', '') .', y: '. number_format($this->_y, 2, '.', '') .', z:'. number_format($this->_z, 2, '.', '') .', w:'. number_format($this->_w, 2, '.', '') .')';
		}
	}
?>