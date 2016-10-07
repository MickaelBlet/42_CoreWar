/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:35:43 by mblet             #+#    #+#             */
/*   Updated: 2016/10/04 23:09:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_process *process)
{
	t_process	*p;
	t_listd		*list;
	int			id;

	DGL;
	id = get_ind_value(process->pc + 1);
	DGL;
	list = sgt_corewar()->processs;
	DGL;
	while (list)
	{
		p = list->data;
		if (p->id == id)
			p->live += 1;
		list = list->next;
	}
	process->pc += 5;
}
