/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:18:44 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/26 18:36:02 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "sh.h"

/*
** Forwards
*/
typedef enum e_token_type	t_token_type;
typedef struct s_token		t_token;

typedef int	(*t_stream_reader)(char **, t_token *);

typedef int	(*t_term_pred)(t_list **);

typedef struct s_ast		t_ast;

/*
** Error Handling
*/
# define ERR_SYNTAX			"Syntax error near "
# define ERR_SYNTAX_START	"<start>"
# define ERR_PARSE			"Parse error near "
# define ERR_PARSE_END		"<end>"

void		syntax_error(t_list *tokens);
void		parse_error(t_list *tokens);

/*
** Lexer
*/
enum	e_token_type
{
	WORD,
	VARIABLE,
	OP_SEMI_COLON,
	OP_PIPE,
	OP_LREDIR,
	OP_RREDIR,
	OP_DRREDIR,
	OP_OR,
	OP_AND,
	OP_AMPERSAND
};

# define WORD_CHARS			"!\\\"#%%'()*+,-./:=?@[]^_{}~"

int			read_word(char **stream, t_token *token);

# define VARIABLE_PREFIX	'$'

int			read_variable(char **stream, t_token *token);
int			read_operator(char **stream, t_token *token);

struct		s_token
{
	int		type;
	char	*lexeme;
};

t_list		*tokenize(t_context *context, char *string);

/*
** Parser
*/
struct		s_ast
{
	t_list	*tokens;
	t_ast	*left;
	t_ast	*right;
};

t_ast		*parse_tokens(t_list *tokens);
int			parse_pipeline(t_list **tokens, t_ast **node);

/*
** Terminal predicate and parsers
*/
int			semi_colon_predicate(t_list **tokens);
int			ampersand_predicate(t_list **tokens);
int			and_or_predicate(t_list **tokens);
int			pipe_predicate(t_list **tokens);
int			redirect_predicate(t_list **tokens);
int			word_predicate(t_list **tokens);

int			terminal_parser(t_list **tokens, t_term_pred pred, t_ast **node);
int			parse_op_semi_colon(t_list **tokens, t_ast **node);
int			parse_op_ampersand(t_list **tokens, t_ast **node);
int			parse_and_or_op(t_list **tokens, t_ast **node);
int			parse_op_pipe(t_list **tokens, t_ast **node);
int			parse_redirect_op(t_list **tokens, t_ast **node);
int			parse_word(t_list **tokens, t_ast **node);

/*
** Abstract syntax tree
*/
t_ast		*ast_new(t_token *token);
void		ast_free_node(t_ast *node);
void		ast_free(t_ast *node);
void		ast_add_token_to_node(t_ast *node, t_token *token);

/*
** Token list conveniency functions
*/
int			terminal(t_list **tokens, int type);
void		next_token(t_list **tokens);
t_token		*get_token(t_list **tokens);
void		free_token(void *p_token, size_t size);
char		*token_value(t_list *tokens, size_t index);
char		**tokens_as_char_array(t_list *tokens);

/*
** Token post processing
*/
void		rearrange_tokens(t_list **tokens);
void		replace_symbols(t_context *context, t_list *tokens);

#endif
