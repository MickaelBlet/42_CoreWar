/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_pc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 09:33:43 by mblet             #+#    #+#             */
/*   Updated: 2016/09/29 11:58:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_ini_reg(t_process *process, int id)
{
	size_t	i;

	i = 0;
	while (i < REG_NUMBER)
	{
		process->reg[i] = 0;
		++i;
	}
	process->reg[0] = id;
}

t_process		*creat_pc(int index, int id, t_byte *b)
{
	t_process	*process;

	if ((process = (t_process *)malloc(sizeof(t_process))) == NULL)
		return (NULL);
	process->id = id;
	process->index = index;
	process->pc = b;
	process->live = 0;
	process->carry = 0;
	process->op_cycle = 0;
	s_ini_reg(process, id);
}
