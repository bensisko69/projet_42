/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschuck <mschuck@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 17:59:30 by mschuck           #+#    #+#             */
/*   Updated: 2014/09/14 18:03:20 by mschuck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	input_content(char *buf, char **content, int *ret, int *len)
{
	char	*tmp;

	if ((tmp = malloc(*len + *ret + 1)) == NULL)
		exit(1);
	if (*content == NULL)
	{
		ft_strcpy(tmp, buf);
		*content = tmp;
		*len = *ret;
		return ;
	}
	ft_strcpy(tmp, *content);
	ft_strcpy(tmp + *len, buf);
	free(*content);
	*len = *len + *ret;
	*content = tmp;
}

char	*read_input(char *s)
{
	int		fd;
	int		ret;
	int		len;
	char	*content;
	char	buf[BFS];

	fd = 0;
	if (s)
	{
		if ((fd = open(s, O_RDONLY)) == -1)
			error_exit(ERO_OPEN);
	}
	content = NULL;
	len = 0;
	while ((ret = read(fd, buf, BFS)) > 0)
	{
		buf[ret] = '\0';
		input_content(buf, &content, &ret, &len);
	}
	if (ret == -1)
		return (NULL);
	close(fd);
	return (content);
}
