/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 13:11:58 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 17:42:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_press_key_sub(t_vm_mlx *mlx)
{
	(void)mlx;
	if (pthread_mutex_trylock(&sgt_mlx()->mutex_key) == 0)
	{
		sgt_corewar()->nb_cycle_per_second -= 50;
		if ((int)sgt_corewar()->nb_cycle_per_second < 0)
			sgt_corewar()->nb_cycle_per_second = 0;
		pthread_mutex_unlock(&sgt_mlx()->mutex_key);
	}
}
