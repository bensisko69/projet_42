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

int     verify_reg(char *s)
{
    if (*s != 'r')
        return (0);
    s++;
    if (!s)
        error_exit("error registre");
    if (*s <'0' || *s > '9')
        error_exit("error registre");
    if (ft_atoi(s) > REG_NUMBER)
    {
        printf("%s r%d > %d\n",ERO_RNBR, ft_atoi(s), REG_NUMBER);
        exit(1);
    }
    if (ft_atoi(s) < 0)
        return (0);
    return (T_REG);
}
