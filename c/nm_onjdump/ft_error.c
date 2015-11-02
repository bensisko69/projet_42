/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 13:22:17 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/01 12:28:42 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_error(int nb)
{
	if (nb == 1)
		ft_putstr_fd(ERROR_FILE, 2);
	if (nb == 2)
		ft_putstr_fd(FILES_ERROR, 2);
	if (nb == 3)
		ft_putstr_fd(FSTAT_ERROR, 2);
	if (nb == 4)
		ft_putstr_fd(MUMMAP_ERROR, 2);
	if (nb == 5)
		ft_putstr_fd(MMAP_ERROR, 2);
	if (nb == 6)
		ft_putstr_fd(OUT_FAILED, 2);
	if (nb == 7)
		ft_putstr_fd(OPEN_FAILED, 2);
	if (nb == 8)
		ft_putstr_fd(FILE_EMPTY, 2);
}