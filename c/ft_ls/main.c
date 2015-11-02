
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:35:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/28 17:18:40 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	int	i;

	i = argc;
	if (argc >= 2 && ft_strcmp(argv[1], "-a") == 0)
		ft_a();
	else if (argc >= 2 && ft_strcmp(argv[1], "-r") == 0)
		ft_r();
	else
		ft_ls();
	return (0);
}
