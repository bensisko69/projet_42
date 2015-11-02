<?
	class Vector
	{
		public static $verbose = False;
		private $_x = 0;
		private $_y = 0;
		private $_z = 0;
		private $_w = 0;

		public function getX(){return $this->$_x;}
		public function getY(){return $this->$_y;}
		public function getZ(){return $this->$_z;}
		public function getW(){return $this->$_w;}

		public function setX($v){return $this->_x = $v;}
		public function setX($v){return $this->_y = $v;}
		public function setX($v){return $this->_z = $v;}
		public function setX($v){return $this->_w = $v;}

		static function doc()
		{
			return file_get_contents("Vector.doc.txt");
		}
		function __construct(array $kwargs)
		{
			
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

		nction __toString()
		{
				return 'Vector( x: '. number_format($this->_x, 2, '.', '') .', y: '. number_format($this->_y, 2, '.', '') .', z:'. number_format($this->_z, 2, '.', '') .', w:'. number_format($this->_w, 2, '.', '') .')';
		}
?>