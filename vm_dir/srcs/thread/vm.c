/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:08:05 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 17:24:30 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*thread_vm(void *e)
{
	t_listd		*list;
	t_process	*process;

	(void)e;
	pthread_mutex_lock(&sgt_corewar()->mutex);
	while (sgt_corewar()->run == true)
	{
		pthread_mutex_lock(&sgt_corewar()->mutex);
		++sgt_corewar()->nbr_cycles;
		list = sgt_corewar()->process;
		while (list != NULL)
		{
			process = list->data;
			process_action(process);
			list = list->next;
		}
		pthread_mutex_unlock(&sgt_corewar()->mutex);
		usleep(10);
	}
	return (NULL);
}
