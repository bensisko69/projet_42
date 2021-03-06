/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:09:27 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/14 19:27:36 by mschuck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*trim(char *line)
{
	char	*end;

	while (*line == ' ' || *line == '\t')
		line++;
	end = line;
	while (*end)
		end++;
	end--;
	while (*end == ' ' || *end == '\t')
	{
		*end = 0;
		end++;
	}
	return (line);
}
