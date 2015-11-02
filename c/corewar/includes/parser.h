/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:10:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/25 17:28:21 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**type
** name = 1
** comment = 2
** label = 3
** inst = 4
*/

#ifndef PARSER_H
# define PARSER_H
# define ERO_ARG "Usage: file_name[.s]..."
# define ERO_OPEN "Open failed."
# define ERO_NM_OR_CMT "Prog_name or comment is an obligatory element."
# define ERO_NBR "T_REG obligatory inferieur at REG_NUMBER"
# define ERO_NM "Error name of insctruction."
# define TRUE 0
# define FALSE 1


# define MORE_CMT "To many comment."
# define MORE_NAME "To many name."
# define OPP_OBL "After label obligatory opperator."
# define MORE_NAME_LABEL "To many name of label."
# define ERROR_T_DIR "Error T_DIR is no good format."
# define ERROR_WORD_LABEL "Word in label == LABEL_CHARS."
# define ERO_LG_NAME "Lenght name is wrong."
# define ERO_LG_CMT "Lenght comment is wrong."
# define DEF_ER_LX ERO_NM, ERO_LG_NAME, ERO_LG_CMT

# define DEF_FUNC3 , {15, aff}
# define DEF_FUNC2 {10, sti}, {11, fork}, {12, lld}, {13, lldi}, DEF_FUNC3
# define DEF_FUNC1 {5, and}, {6, or}, {7, xor}, {8, zjmp}, {9, ldi}, DEF_FUNC2
# define DEF_FUNC {0, live}, {14, live}

# define DEF ERROR_T_DIR, ERROR_WORD_LABEL

# include "op.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list	t_list;
typedef struct s_func	t_func;
typedef int (*t_inst_func)(char *, t_list **);

struct			s_func
{
	int			nb_line;
	t_inst_func	func;
}				;

struct			s_list
{
	int			type;
	int			start; // 1 first elem, 0 next elem
	int			type_arg; // T_REG, T_DIR, T_IND ou T_LAB
	int			opcode; // correspond a l'instruction en hexa, index ds le tableau
	char		*str; // contient la string
	t_header	header; // struct op.h
	t_list		*next;
	t_list		*prev;
}				;

void			ft_list_push(char *line, t_list **list);
void			print_list(t_list *list);

int				parse(t_list **list);
void			ft_error(int nb);
int				ft_pars_lex(t_list **list);
void			parse_op(t_list **list);
void			parse_label(t_list **list);

void			check_tab(char *str, t_list **list);
int				check_start_end(char *str, t_list **list);
int				check_type(t_list **list);

int				cut_str(char *str, int cut, t_list **list, int c);

int				lexer(t_list **list);
int				check_nb_cmt_or_name(t_list **list);
int				check_label(t_list **list);
int				check_inst(t_list **list);

int				parse_dir(t_list **list, char *str, int *pos);
int				parse_reg(t_list **list, char *str, int pos);
int				live(char *str, t_list **list);

#endif
