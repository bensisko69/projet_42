/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:09:27 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/1s1/11 17:41:05 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void print_header(header_t h)
{
    printf("name progr : (%s)\n",h.prog_name);
    printf(" comment : (%s)\n",h.comment);
}

int	main(int ac, char **av)
{
	(void)g_op_tab;
	t_list      *list;
	t_list      *label;
	header_t    h;
    char        *data;

	if (ac != 2)
		error_exit(ERO_ARG);
	list = NULL;
	label = NULL;
    data = read_input(av[1]);
    if (!data)
        error_exit("error parser");
    ft_bzero(&h, sizeof(h));
    parser(&label, &h, data);
    print_header(h);
  //  print_label(label);
	//print_list(list);
	//dbg_header(h);
	return (0);
}