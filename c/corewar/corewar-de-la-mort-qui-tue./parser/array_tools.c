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
void       array_print(char **sp)
{
    char    **next;
    
    if (!sp)
        return ;
    next = sp;
    while (*sp)
    {
        next = sp + 1;
        printf(">%s\n", *sp);
        sp = next;
    }
    printf("\n");
}

void        array_free(char ***sp)
{
    char    **head;
    char    **next;
    
    if (!*sp)
        return ;
    head = *sp;
    next = *sp;
    while (**sp)
    {
        next = *sp + 1;
        free(**sp);
        *sp = next;
    }
    free(head);
}

int       array_len(char **sp)
{
    char    **next;
    int     len;
    
    if (!sp)
        return (0);
    next = sp;
    len = 0;
    while (*sp)
    {
        next = sp + 1;
        len++;
        sp = next;
    }
    return (len);
}

char    **array_split(char *str)
{
    char    **sp;
    char    *eol;
    char    *ptr;
    int     i;

    sp = malloc(sizeof(char *) * 5);
    if (!sp)
        return (0);
    ptr = str;
    i = -1;
    while (ptr && *ptr)
    {
        if (is_blank(*ptr))
        {
            *ptr = 0;
            if ((eol = ft_strchr(str, ',')))
                *eol = 0;
            sp[++i] = trim(ft_strdup(str));
            if (!*(sp[i]))
                i--;
            ptr++;
            str = ptr;
        }
        ptr++;
    }
    sp[++i] = trim(ft_strdup(str));
    sp[i + 1] = 0;
    return (sp);
}