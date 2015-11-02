/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 15:47:50 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/15 23:43:37 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

//0 char
//1 int
//2 double
//3 float

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool	ft_isalpha(char c)
{
	if (c >= 33 && c <= 126)
		return true;
	return false;
}

int pars(char *str)
{
	int a = 0;
	if (!str)
		return -1;
	if (ft_isalpha(str[a]) == true && ft_isdigit(str[a]) == false)
	{
		a++;
		if (str[a] == '\0')
			return 0;
		else if (ft_isdigit(str[a]) == false)
			return -1;
	}
	while (ft_isdigit(str[a]) == true || str[a] == '-')
		a++;
	if (str[a] == '\0')
		return 1;
	if (str[a] == '.' && ft_isdigit(str[a + 1]) == false)
		return -1;
	if (str[a] == '.')
		a++;
	while (ft_isdigit(str[a]) == true)
		a++;
	if (str[a] == '\0')
		return 2;
	if (str[a] == 'f')
		return 3;
	return -1;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (*s1 == *s2 && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		ft_cmp(char *str)
{
	if (ft_strcmp(str, "-inff") == 0 || ft_strcmp(str, "+inff") == 0 || ft_strcmp(str, "nanf") == 0)
		return 3;
	if (ft_strcmp(str, "-inf") == 0 || ft_strcmp(str, "+inf") == 0 || ft_strcmp(str, "nan") == 0)
		return 2;
	return -1;
}

void	toint(int i, char c, double d, float f, char *str)
{
	i = static_cast<int>(atoi(str));
	if (i >= 33 && i <= 126)
	{
		c = static_cast<char>(i);
		std::cout << "char: " << "'" << c << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable " << std::endl;
	std::cout << "int: " << i << std::endl;
	f = static_cast<float>(i);
	std::cout << "float: " << f << ".0f" << std::endl;
	d = static_cast<double>(i);
	std::cout << "double: " << d << ".0" << std::endl;

}

void	tofloat(int i, char c, double d, float f, char *str)
{
	f = static_cast<float>(atof(str));
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	if (i >= 33 && i <= 126)
	{
		c = static_cast<char>(f);
		std::cout << "char: " << "'" << c << "'" << std::endl;
	}
	else
		std::cout << "char: impossible " << std::endl;
	if (ft_cmp(str) != 3)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	todouble(int i, char c, double d, float f, char *str)
{
	d = static_cast<double>(atof(str));
	f = static_cast<float>(d);
	i = static_cast<int>(d);
	if (i >= 33 && i <= 126)
	{
		c = static_cast<char>(d);
		std::cout << "char: " << "'" << c << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (ft_cmp(str) != 2)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f"<< std::endl;
	std::cout << "double: " << d << std::endl;
}

void	tochar(int i, char c, double d, float f, char *str)
{
	c = static_cast<char>(str[0]);
	if (c >= 33 && c <= 126)
	{
		std::cout << "char: " << "'" << c  << "'"<< std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	d = static_cast<double>(c);
	f = static_cast<float>(c);
	i = static_cast<int>(c);
	if (ft_cmp(str) != 2)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

int	main(int ac, char **av)
{
	int i = 0;
	char c = 0;
	double d = 0.0;
	float f = 0.0f;
	int a = 42;
	int	b = 42;
	if (ac != 2)
		return -1;
	a = pars(av[1]);
	if (a == 1)
		toint(i, c, d, f, av[1]);
	else if ((a == 3) || (b = ft_cmp(av[1])) == 3)
		tofloat(i, c, d, f, av[1]);
	else if ((a == 2) || (b = ft_cmp(av[1])) == 2)
		todouble(i, c, d, f, av[1]);
	else if (a == 0)
		tochar(i, c, d, f, av[1]);
	return 0;
}