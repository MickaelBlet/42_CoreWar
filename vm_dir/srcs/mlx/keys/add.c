/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 13:11:02 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 13:59:21 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_press_key_add(t_vm_mlx *mlx)
{
	(void)mlx;
	if (pthread_mutex_trylock(&sgt_mlx()->mutex_key) == 0)
	{
		sgt_corewar()->nb_cycle_per_second += 50;
		pthread_mutex_unlock(&sgt_mlx()->mutex_key);
	}
}
