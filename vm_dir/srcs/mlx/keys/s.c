/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 16:31:50 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 14:00:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** STEP BY STEP
*/
void	vm_press_key_s(t_vm_mlx *mlx)
{
	(void)mlx;
	if (pthread_mutex_trylock(&sgt_mlx()->mutex_key) == 0)
	{
		pthread_mutex_unlock(&sgt_corewar()->mutex);
		pthread_mutex_lock(&sgt_corewar()->mutex);
		sgt_mlx()->pause = true;
		pthread_mutex_unlock(&sgt_mlx()->mutex_key);
	}
}
