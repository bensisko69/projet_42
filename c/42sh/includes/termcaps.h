/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 21:19:27 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 15:31:36 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include "sh.h"

typedef struct s_line_edit	t_line_edit;

typedef int	(*t_seq_action)(t_context *, t_line_edit *);

/*
** Error handling
*/
# define ERR_NO_TERM_TYPE		"could not determine the terminal type"
# define ERR_ENTRY_LOAD			"error loading the terminal entry for"
# define ERR_TCGETATTR			"could not get terminal attributes"
# define ERR_TCSETATTR			"could not set terminal attributes"
# define ERR_NO_SUCH_CAP		"no such terminal capability"
# define ERR_NO_TTY				"Error opening a tty device"

/*
** Front end read function
*/
# define KEY_BUFF_SIZE			8
# define LINE_BUFF_SIZE			4096

# define READ_STOP				0
# define READ_CONTINUE			1

char		*read_line(t_context *context, int fd);

/*
** Line edition
*/
struct		s_line_edit
{
	char	line[LINE_BUFF_SIZE];
	size_t	pos;
	size_t	len;
};

void		line_insert(t_line_edit *line_edit, char *str, size_t len);
void		line_remove(t_line_edit *le, size_t len);

/*
** terminal command conveniency functions
*/
int			tputs_putchar(int c);
void		term_command(char *capability);
void		term_param_command(char *capability, int n);
void		term_command_n(char *capability, size_t n);

/*
** Capabilities
*/
# define CAP_CURSOR_LEFT		"le"
# define CAP_CURSOR_RIGHT		"nd"
# define CAP_DEL_ONE_CHAR		"dc"
# define CAP_INSERT_MODE		"im"
# define CAP_END_INSERT			"ei"
# define CAP_CLEAR_SCREEN		"cl"

/*
** Key mapping
*/
int			handle_key(t_context *context, t_line_edit *le,
						char *key, size_t len);
t_map		*get_key_map(void);
void		free_key_map(void);

# define SEQ_NEW_LINE			"\x0a"

int			on_key_new_line(t_context *context, t_line_edit *line_edit);
# define SEQ_TAB				"\x9"

int			on_key_tab(t_context *context, t_line_edit *line_edit);
# define SEQ_BACKSPACE			"\x7f"

int			on_key_backspace(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_D				"\x4"

int			on_key_ctrl_d(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_L				"\xc"

int			on_key_ctrl_l(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_W				"\x17"

int			on_key_ctrl_w(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_K				"\xb"

int			on_key_ctrl_k(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_A				"\x1"

int			on_key_ctrl_a(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_E				"\x5"

int			on_key_ctrl_e(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_U				"\x15"

int			on_key_ctrl_u(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_H				"\x8"

int			on_key_ctrl_h(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_G				"\x7"

int			on_key_ctrl_g(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_C				"\x3"

int			on_key_ctrl_c(t_context *context, t_line_edit *line_edit);
# define SEQ_CTRL_F				"\x6"

int			on_key_ctrl_f(t_context *context, t_line_edit *line_edit);
# define SEQ_ALT_LEFT			"\x1b\x1b\x5b\x44"

int			on_key_alt_left(t_context *context, t_line_edit *line_edit);
# define SEQ_ALT_RIGHT			"\x1b\x1b\x5b\x43"

int			on_key_alt_right(t_context *context, t_line_edit *line_edit);
# define SEQ_ALT_UP				"\x1b\x1b\x5b\x41"

int			on_key_alt_up(t_context *context, t_line_edit *line_edit);
# define SEQ_ALT_DOWN			"\x1b\x1b\x5b\x42"

int			on_key_alt_down(t_context *context, t_line_edit *line_edit);
# define SEQ_LEFT_ARROW			"\x1b\x5b\x44"

int			on_key_left_arrow(t_context *context, t_line_edit *line_edit);
# define SEQ_RIGHT_ARROW		"\x1b\x5b\x43"

int			on_key_right_arrow(t_context *context, t_line_edit *line_edit);
# define SEQ_UP_ARROW			"\x1b\x5b\x41"

int			on_key_up_arrow(t_context *context, t_line_edit *line_edit);
# define SEQ_DOWN_ARROW			"\x1b\x5b\x42"

int			on_key_down_arrow(t_context *context, t_line_edit *line_edit);

/*
** Terminal modes
*/
void		termcaps_init(t_context *context);
void		term_set_raw_mode(t_context *context);
void		term_restore_mode(t_context *context);

/*
** tty
*/
int			tty_fd(void);
void		close_tty(void);

#endif
