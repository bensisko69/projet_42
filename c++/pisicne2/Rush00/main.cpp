/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 18:19:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 22:52:40 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <unistd.h>

int	main(int ac, char **av)
{
	srand(time(0));
	if (!isatty(STDIN_FILENO))
	{
		std::cout << "stdin id not a tty" << std::endl;
		return 0;
	}
	if (ac == 2)
	{
		std::string	param(av[1]);
		if (param == "help")
		{
			std::cout << "Two game modes: " << std::endl;
			std::cout << "- hard = max enemies." << std::endl;
			std::cout << "- dodge = max enemies but no shot." << std::endl;
			std::cout << "- cheating." << std::endl;
			std::cout << "enter your choice : ";
			std::getline(std::cin, param) ;
		}
		if (param == "hard")
			GameEngine::i = 8;
		else if (param == "dodge")
			GameEngine::i = 3;
		else if (param == "cheating")
			GameEngine::i = 1;
	}
	GameEngine		game;
	while (game.render())
		;
	return (0);
}
