#include "../includes/parser.h"
void    choose(char *s, t_list **l)
{
    
    char    *head;
    char    *eol;

    head = s;
    if (!(eol = ft_strchr(head, ':')))
        record_instr(head, l);
    else
    {
        if ((eol = ft_strchr(head, ':')) && !ft_strchr(head, '%'))
            record_label(head, l);
        else
            record_instr(head, l);
    }

}
char    *define(char *s, t_list **l)
{
    char    *eol;
    char    *back;
    char    *cpy;
    
    cpy = ft_strdup(s);
    eol = ft_strchr(cpy, '\n');
    if (eol)
        *eol = 0;
    choose(cpy, l);
    back = ft_strchr(s, '\n');
    if (!back)
    {
        while (s && *s != 0)
            s++;
        return s - 1;
    }
    return back;
}
char    *trim_comment(char *s)
{
    while (s && *s != 0)
    {
        if (*s == '\n')
        {
            s++;
            break ;
        }
        s++;
    }
    return s;
}
void    parser(t_list **l, header_t *h, char *s)
{
    while (s && *s != 0)
    {
        if (*s == COMMENT_CHAR)
            s = trim_comment(s);
        if (ft_strncmp(".name", s, 5) == 0)
            s += set_header_name(h, s, 6);
        else if (ft_strncmp(".comment", s, 8) == 0)
            s += set_header_cmt(h, s, 9);
        else if (ft_strchr(LABEL_CHARS, *s))
            s = define(s, l);
        s++;
    }
    ft_iter_label(*l, instr_inlabel);
}