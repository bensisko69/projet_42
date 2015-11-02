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

static void     recheck(char *s, t_list *list)
{
    int i;
    
    i = 0;
    if (list->start == 1)
        list = list->next;
    while (list->start != 1)
    {
        if (list->type == ITERLABEL)
        {
            if (ft_strcmp(s, list->data) == 0)
                i++;
        }
        list = list->next;
    }
    if (list->type == ITERLABEL)
    {
        if (ft_strcmp(s, list->data) == 0)
            i++;
    }
    if (i == 0)
        error_exit(ft_strjoin("error label ",s));
}

static void    label_error(void *label, t_instr *i, t_list *l)
{
    char    **sp;
    char    **next;
    char    *word;
    
    sp = i->data;
    next = sp;
    while (*sp)
    {
        next = sp + 1;
        word = *sp;
        if (ft_strchr(word, DIRECT_CHAR) && ft_strchr(word + 1, LABEL_CHAR))
        {
            word += 2;
            if (ft_strcmp(word, (char*)label) != 0)
                recheck(word, l);
        }
        sp = next;
    }
}

void     instr_inlabel(void *label, t_list *list)
{
    t_list  *e;
    
    e = list;
    if (list->start == 1)
        list = list->next;
    while(list->start != 1)
    {
        if (list->type == ITERINSTR)
            label_error(label, (t_instr *)list->data, e);
        list = list->next;
    }
    if (list->type == ITERINSTR)
        label_error(label, (t_instr *)list->data, e);
}

void    record_label(char *str, t_list **lst)
{
    char    *head;
    
    head = str;
    while (str && *str != LABEL_CHAR)
        str++;
    *str = 0;
    if (!head)
        return ;
    if (!*head)
        return ;
    ft_list_push(ITERLABEL, head, lst);
}
