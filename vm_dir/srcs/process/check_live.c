/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 00:14:23 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 02:35:30 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_bool	s_del(t_listd **list, t_process *process)
{
	if ((*list)->prev == NULL
		&& (process->live <= sgt_corewar()->last_cycle_check
			|| sgt_corewar()->cycle_to_die < 0))
	{
		verbose_death(process);
		pthread_mutex_lock(&sgt_corewar()->mutex_process);
		ft_lstd_pop_front(&sgt_corewar()->process, NULL);
		pthread_mutex_unlock(&sgt_corewar()->mutex_process);
		*list = sgt_corewar()->process;
		return (true);
	}
	else if (process->live <= sgt_corewar()->last_cycle_check
		|| sgt_corewar()->cycle_to_die < 0)
	{
		verbose_death(process);
		pthread_mutex_lock(&sgt_corewar()->mutex_process);
		ft_lstd_del(list, NULL);
		pthread_mutex_unlock(&sgt_corewar()->mutex_process);
		return (true);
	}
	return (false);
}

void			process_check_live(void)
{
	t_listd		*list;
	t_process	*process;

	list = sgt_corewar()->process;
	while (list)
	{
		process = list->data;
		if (s_del(&list, process) == false)
			list = list->next;
	}
}
