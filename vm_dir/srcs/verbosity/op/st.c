/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:46:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 16:54:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_if_reg(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (arg[0] <= 0 || arg[0] > REG_NUMBER
		|| arg[1] <= 0 || arg[1] > REG_NUMBER)
		return ;
	ft_printf("P %4u | %s r%i r%i\n",
			process->uid, process->op.name,
			arg[0], arg[1]);
}

static void		s_if_not_reg(t_process *process, int type[4], int arg[4])
{
	if (arg[0] <= 0 || arg[0] > REG_NUMBER)
		return ;
	if (type[1] == T_IND)
	{
		ft_printf("P %4u | %s r%i %i\n",
				process->uid, process->op.name,
				arg[0], arg[1]);
	}
	else
	{
		ft_printf("P %4u | %s r%i %i\n",
				process->uid, process->op.name,
				arg[0], arg[1]);
	}
}

void			verbose_op_st(t_process *process, int type[4], int arg[4])
{
	if (type[1] == T_REG)
		s_if_reg(process, type, arg);
	else
		s_if_not_reg(process, type, arg);
}
