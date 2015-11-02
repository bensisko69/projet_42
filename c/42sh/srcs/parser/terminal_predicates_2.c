/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_predicates_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 01:44:03 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 01:44:44 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			word_predicate(t_list **tokens)
{
	return (terminal(tokens, WORD));
}
