/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:37:18 by mblet             #+#    #+#             */
/*   Updated: 2016/11/07 00:19:24 by mblet            ###   ########.fr       */
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

t_process		*process_creat(size_t index, int id, int color_id)
{
	t_process		*process;
	static size_t	uid = 1;

	if ((process = (t_process *)malloc(sizeof(t_process))) == NULL)
		return (NULL);
	process->uid = uid++;
	process->id = id;
	process->pc = index;
	s_ini_reg(process, id);
	process->live = 0;
	process->carry = 0;
	process->op = op_tab(16);
	process->op_cycle = 0;
	process->in_action = false;
	process->color_id = color_id;
	return (process);
}
