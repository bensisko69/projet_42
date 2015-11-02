/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_terminals_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 23:36:10 by kpoirier          #+#    #+#             */
/*   Updated: 2014/03/14 01:44:16 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_op_semi_colon(t_list **tokens, t_ast **node)
{
	return (terminal_parser(tokens, semi_colon_predicate, node));
}

int		parse_op_ampersand(t_list **tokens, t_ast **node)
{
	return (terminal_parser(tokens, ampersand_predicate, node));
}

int		parse_and_or_op(t_list **tokens, t_ast **node)
{
	return (terminal_parser(tokens, and_or_predicate, node));
}

int		parse_op_pipe(t_list **tokens, t_ast **node)
{
	return (terminal_parser(tokens, pipe_predicate, node));
}

int		parse_redirect_op(t_list **tokens, t_ast **node)
{
	return (terminal_parser(tokens, redirect_predicate, node));
}
