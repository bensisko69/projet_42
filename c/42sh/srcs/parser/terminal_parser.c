/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:50:16 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/12 15:50:29 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	terminal_parser(t_list **tokens, t_term_pred pred, t_ast **node)
{
	if (pred(tokens))
	{
		ast_add_token_to_node(*node, get_token(tokens));
		next_token(tokens);
		return (1);
	}
	return (0);
}
