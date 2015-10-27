/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 12:38:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/26 18:00:42 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define WRITE(fd, const_str) write(fd, const_str, sizeof(const_str))

void	test_isalpha();
void	test_isalpha();
void	test_isdigit();
void	test_isalnum();
void	test_isascii();
void	test_isprint();
void	test_toupper();
void	test_tolower();
void	test_bzero();
void	test_strcat();
void	test_puts();
void	test_memset();
void	test_memcpy();
void	test_strdup();
void	test_strlen();
void	test_cat();

void	ft_putnbr(int n);
int		ft_isascii(int i);
int		ft_isalpha(int i);
int		ft_isalnum(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
int		ft_tolower(int i);
int		ft_toupper(int i);
void	ft_bzero(void *s, size_t n);
int		ft_puts(const char *str);
char	*ft_strcat(char *dest, const char *src);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const char *src, size_t n);
char	*ft_strdup(const char *s);
int		ft_strlen(char *str);
int		ft_cat(int fd);

#endif
