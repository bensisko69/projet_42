/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_button.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:30:08 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/02/03 18:30:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_BUTTON_H
# define FUNC_BUTTON_H
# define TAB {KEY_ARROW_LEFT, arrow_left}, {KEY_ARROW_UP, arrow_left}, TB2
# define TB2 {KEY_ARROW_RIGHT, arrow_right}, TB3
# define TB3 {KEY_ARROW_DOWN, arrow_right}, {KEY_DELETE, ft_delete}, TB4
# define TB4 {KEY_BACKSPACE, ft_delete}, {KEY_ESC, esc}, TB5
# define TB5 {KEY_SPACE, space}, {KEY_ENTER, enter}
# include "select.h"

void	key_pressed(t_list **list, t_list **current, char *key_code);
#endif
