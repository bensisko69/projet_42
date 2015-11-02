/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_terminals_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 01:43:56 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 01:44:25 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_word(t_list **tokens, t_ast **node)
{
	return (terminal_parser(tokens, word_predicate, node));
}
