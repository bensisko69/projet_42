/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:09:27 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/11 17:41:05 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void error_num(char c)
{
    if (c < '0' || c > '9')
        error_exit("error t_ind num");
}

static void error_label(char c)
{
    if (!ft_strchr(LABEL_CHARS, c))
        error_exit("error t_ind label");
}

int     verify_indir(char *s)
{
    if (!s)
        error_exit("error t_ind code");
    if ((*s >= '0' && *s <= '9') || *s == '-')
    {
        s = (*s == '-') ? s + 1 : s;
        iter_str(s, error_num);
        return (T_IND);
    }
    if (s + 1)
    {
        if (*s == DIRECT_CHAR && *(s + 1) == LABEL_CHAR)
        {
            s += 2;
            iter_str(s, error_label);
            return (T_IND);
        }
    }
    return (0);
}

