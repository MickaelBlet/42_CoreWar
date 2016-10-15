/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:37:54 by mblet             #+#    #+#             */
/*   Updated: 2016/10/13 23:34:35 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_fork_reg(t_process *new, t_process *process)
{
	size_t	i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = process->reg[i];
		++i;
	}
}

t_process		*process_fork(t_process *process, size_t index)
{
	t_process	*new;

	if ((new = (t_process *)malloc(sizeof(t_process))) == NULL)
		return (NULL);
	new->id = process->id;
	new->pc = index;
	s_fork_reg(new, process);
	new->live = process->live;
	new->carry = process->carry;
	new->op = op_tab(16);
	new->op_cycle = process->op_cycle;
	new->color_id = process->color_id;
	return (new);
}
