<?php
	session_start();
	if ($_GET['submit'] == 'OK')
	{
		$_SESSION['login'] = $_GET['login'];
		$_SESSION['passwd'] = $_GET['passwd'];
	}
?>
<html>
	<style>
		body
		{
			background: url(http://didoune.fr/blog/wp-content/uploads/2014/03/Game-of-Thrones-recap.jpg);
			background-repeat:no-repeat;
			background-position: center;
		}
		#post
		{
			position: absolute;
			top: 40%;
			left: 45%;
			height: 180px;
			width: 280px;
			border: 2px solid white;
			border-radius: 30px;
		}
		#top
		{
			margin-top: 10px;
			margin-right: 15px;
			width: 150px;
		}
		#bot
		{
			width: 150px;
		}
		p
		{
			font-size: 25px;
			color: red;
		}
		#submit
		{
			width: 60px;
			font-size: 200px;
		}
	</style>
	<body>
		<center>
			<form method="get" action="index.php">
			<div id="post">
				<p><input id="top" type="text" name="login" value=<?PHP echo $_SESSION['login'] ?>> login </p>
				<p><input id="bot" type="password" name="passwd" value=<?PHP echo $_SESSION['passwd'] ?>> passwd </p>
				<input id="submit" type="submit" name="submit" value="OK" />
				</div>
			</form>
		</center>
	</body>
</html>