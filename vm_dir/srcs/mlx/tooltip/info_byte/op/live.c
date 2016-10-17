/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:35:43 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 23:13:52 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_op_live(t_process *process, int type[4], int arg[4])
{
	t_listd		*list;
	t_process	*tmp_process;

	(void)type;
	(void)arg;
	(void)process;
	(void)list;
	(void)tmp_process;
	/*list = sgt_corewar()->process;
	while (list != NULL)
	{
		tmp_process = list->data;
		if (tmp_process != NULL && tmp_process->id == arg[0])
			tmp_process->live += 1;
		list = list->next;
	}*/
	process->carry = 1;
}
