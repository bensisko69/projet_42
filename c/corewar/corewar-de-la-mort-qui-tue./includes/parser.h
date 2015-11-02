/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:10:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/13 18:09:54 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSER_H
# define PARSER_H
# define ERO_ARG "Usage: file_name[.s]..."
# define ERO_OPEN "Open failed."
# define ERO_NAME_OR_CMT "Prog_name or comment is an obligatory element."
# define ERO_RNBR "T_REG obligatory inferieur at REG_NUMBER."
//# define ERO_DIR "Usage: %nbr or %:label."

# include "op.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define BFS 8192

# define ITERLABEL 0
# define ITERINSTR 1

typedef struct s_list t_list;


typedef struct s_instr
{
    int         param_type[3];
    char        code[16];
    int         error;
    char        **data;
    char        *opcode;
    char        *octet_codage;
}               t_instr;

struct s_list
{
	int			type;	//label | instruction
	int			start; // 1 first elem, 0 next elem
	t_list		*next;
	t_list		*prev;
    void        *data;
};

void    record_label(char *str, t_list **lst);
void     instr_inlabel(void *label, t_list *list);
void    record_instr(char *str, t_list **lst);
void    parser(t_list **l, header_t *h, char *s);

int     set_header_name(header_t *h, char *s, int i);
int     set_header_cmt(header_t *h, char *s, int i);

int     verify_reg(char *s);
int     verify_dir(char *s);
int     verify_indir(char *s);


int     is_blank(char c);
void    iter_str(char *s, void (*f)(char));

void    array_print(char **sp);
void    array_free(char ***sp);
int     array_len(char **sp);
char    **array_split(char *str);

char	*read_input(char *s);
/*
void	parser(header_t *h, t_list **list, t_list **label, char *filename);
 void	ft_list_push(char *line, t_list **list);
*/

void	ft_list_push(int type, void *data, t_list **list);
void    ft_iter_label(t_list *list, void (*f)(void *, t_list *));


void	error_exit(char *s);
void	ft_error(int nb);


#endif
