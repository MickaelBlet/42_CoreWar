/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:08:05 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 15:24:35 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*thread_vm(void *e)
{
	(void)e;
	pthread_mutex_lock(&sgt_corewar()->mutex);
	while (sgt_corewar()->run)
	{
		pthread_mutex_lock(&sgt_corewar()->mutex);
		pthread_mutex_unlock(&sgt_corewar()->mutex);
		cycle();
		if (sgt_corewar()->nb_cycle_per_second > 0)
			usleep(1000000 / sgt_corewar()->nb_cycle_per_second);
	}
	win();
	return (NULL);
}
