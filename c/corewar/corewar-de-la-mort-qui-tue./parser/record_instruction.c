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

static char    *trim_instr(char *str)
{
    char    *eol;
    
    eol = str;
    if ((eol = ft_strchr(str, ';')))
        *eol = 0;
    eol = str;
    while (eol && *eol)
        eol++;
    eol--;
    while (eol && is_blank(*eol))
    {
        *eol = 0;
        eol--;
    }
    return (str);
}

static void    set_instruction(char *str, t_op op, t_instr *instr)
{
    (void)str;
    (void)op;
    (void)instr;
  //  printf("check (%s) get (%s)\n",op.inst, str);
}
void    print_instr(t_instr *instr)
{
    printf("====\n");
    printf("instru : %s\n",*(instr->data));
    printf("opcode : %s\n",instr->opcode);
    printf("octet_codage : %s\n",instr->octet_codage);
    printf("=====END======\n");

}

void    set_octet_codage(t_instr *instr)
{
    int         j;
    int         i;
    char        *tobin;
    char        tab[8];
    static char *oct[4] = {"00", "01", "10", "11"};
    
    ft_bzero(tab, 8);
    i = -1;
    while (++i < 3)
    {
        tobin = ft_itob(instr->param_type[i]);
        tobin = tobin + ft_strlen(tobin) - 2;
        j = -1;
        while (++j < 3)
        {
            if (ft_strcmp(tobin, oct[j]) == 0)
                ft_memcpy(tab + i * 2, tobin, 2);
        }
   //     printf("to bin : (%s)\n",tobin);
    }
   // printf("tab = (%s)\n", tab);
    instr->octet_codage = ft_btoh(tab);// ft_strdup("00");
}

static void    verify_instruction(t_op op, t_instr *instr)
{
    int     i;
    char    **sp;

    sp = instr->data;
    if (array_len(sp) - 1 != op.nb_param)
        error_exit(ft_strjoin("error num args instruction parameters ", op.inst));
    sp++;
    i = -1;
    while (++i < op.nb_param)
    {
        printf("\t:: %d %s \t \n",op.param[i], sp[i]);
        if (op.param[i] == T_REG)
            instr->param_type[i] = verify_reg(sp[i]);
        else if (op.param[i] == T_DIR)
            instr->param_type[i] = verify_dir(sp[i]);
        else if (op.param[i] == T_IND)
            instr->param_type[i] = verify_indir(sp[i]);
        else if (op.param[i] == 3)
            instr->param_type[i] = verify_dir(sp[i]) | verify_reg(sp[i]);
        else if (op.param[i] == 5)
            instr->param_type[i] = verify_indir(sp[i]) | verify_reg(sp[i]);
        else if (op.param[i] == 6)
            instr->param_type[i] = verify_indir(sp[i]) | verify_dir(sp[i]);
        else if (op.param[i] == 7)
        {
            if (verify_reg(sp[i]))
                instr->param_type[i] = verify_reg(sp[i]);
            else if (verify_dir(sp[i]))
                instr->param_type[i] = verify_dir(sp[i]);
            else
                instr->param_type[i] = verify_indir(sp[i]);
        }
        if (!instr->param_type[i])
            error_exit(ft_strjoin("error type instruction parameters ", *(instr->data)));
    }
    i = -1;
    while (++i < op.nb_param)
    {
        printf(">> %d ",instr->param_type[i] );
        if (instr->param_type[i] == T_REG)
            printf("T_REG ");
        else if (instr->param_type[i] == T_DIR)
            printf("T_DIR ");
        else if (instr->param_type[i] == T_IND)
            printf("T_IND ");
    }
    printf("\n");
    if (op.octet_codage == 1)
        set_octet_codage(instr);
    else
        printf("\nNO octet codage\n");
    print_instr(instr);
}


void    record_instr(char *str, t_list **lst)
{
    t_instr     *instr;
    int         i;
    char        **sp;

    str = trim_instr(str);
/*   
    if (!ft_strchr(str, ' ') && !ft_strchr(str, '\t'))
        error_exit("error instr");
*/
    if (!(sp = array_split(str)))
        error_exit("error parse");
    if (array_len(sp) <= 1)
        error_exit("error parse");
    if (!(instr = malloc(sizeof(*instr))))
        error_exit("error parse");
    ft_bzero(instr, sizeof(*instr));
    instr->data = sp;
    instr->error = -1;
    i = -1;
    while (++i < 16)
    {
        if (ft_strcmp(g_op_tab[i].inst, sp[0]) == 0)
        {
            instr->opcode = ft_itoh(i + 1);
            verify_instruction(g_op_tab[i], instr);
            set_instruction(str, g_op_tab[i], instr);
            instr->error = 0;
        }
    }
    if (instr->error)
        error_exit(ft_strjoin("error 1 unknow instruction parameters ", *(instr->data)));
    ft_list_push(ITERINSTR, instr, lst);
}
