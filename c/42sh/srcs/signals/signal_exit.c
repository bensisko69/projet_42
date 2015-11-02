/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 17:26:03 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/15 17:29:34 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	on_signal_exit(int sig)
{
	UNUSED(sig);
	shell_exit(get_context(), EXIT_ERROR);
}
