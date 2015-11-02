/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/25 15:58:31 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/09/25 23:38:06 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define SIZE_TINY 1
# define SIZE_SMALL 10
# include <stddef.h>
# include <sys/mman.h>
# include "libft/includes/libft.h"

typedef struct s_size	t_size;

struct			s_size
{
	int			free;
	void		*next;
	int			size;
}				;

#endif
