/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:42:02 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 17:43:31 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_press_key_0(t_vm_mlx *mlx)
{
	(void)mlx;
	if (pthread_mutex_trylock(&sgt_mlx()->mutex_key) == 0)
	{
		sgt_corewar()->nb_cycle_per_second += 10;
		pthread_mutex_unlock(&sgt_mlx()->mutex_key);
	}
}
