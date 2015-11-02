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

int     set_header_name(header_t *h, char *s, int i)
{
    char    *get;
    char    *eol;

    s = s + i;
    if (!s)
        return 0;
    while (s && is_blank(*s))
    {
        i++;
        s++;
    }
    while (s && *s == '"')
    {
        i++;
        s++;
    }
    get = ft_strdup(s);
    if (!(eol = ft_strchr(get, '"')))
        error_exit("error get name \n");
    *eol = 0;
    if (ft_strlen(get) >= PROG_NAME_LENGTH)
        error_exit("error get name len\n");
    i += (int)(eol - get);
    ft_memcpy(h->prog_name, get, ft_strlen(get));
    if (!h->prog_name)
        exit(1);
    free(get);
    return (i + 1);
}

int     set_header_cmt(header_t *h, char *s, int i)
{
    char    *get;
    char    *eol;
    
    s = s + i;
    if (!s)
        return 0;
    while (s && is_blank(*s))
    {
        i++;
        s++;
    }
    while (s && *s == '"')
    {
        i++;
        s++;
    }
    get = ft_strdup(s);
    if (!(eol = ft_strchr(get, '"')))
        error_exit("error get cmt \n");

    *eol = 0;
    if (ft_strlen(get) >= COMMENT_LENGTH)
        error_exit("error get cmt len \n");

    i += (int)(eol - get);
    ft_memcpy(h->comment, get, ft_strlen(get));
    if (!h->comment)
        exit(1);
    free(get);
    return (i);
}
