/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_predicates_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:44:50 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:35:45 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			semi_colon_predicate(t_list **tokens)
{
	return (terminal(tokens, OP_SEMI_COLON));
}

int			ampersand_predicate(t_list **tokens)
{
	return (terminal(tokens, OP_AMPERSAND));
}

int			and_or_predicate(t_list **tokens)
{
	return (terminal(tokens, OP_OR) || terminal(tokens, OP_AND));
}

int			pipe_predicate(t_list **tokens)
{
	return (terminal(tokens, OP_PIPE));
}

int			redirect_predicate(t_list **tokens)
{
	return (terminal(tokens, OP_LREDIR)
	|| terminal(tokens, OP_RREDIR)
	|| terminal(tokens, OP_DRREDIR));
}
