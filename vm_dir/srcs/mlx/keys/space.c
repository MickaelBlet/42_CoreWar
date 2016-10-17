/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 19:47:54 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 19:56:35 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** PAUSE & RUN
*/
void	vm_press_key_space(t_vm_mlx *mlx)
{
	(void)mlx;
	if (pthread_mutex_trylock(&sgt_corewar()->mutex) != 0)
		pthread_mutex_unlock(&sgt_corewar()->mutex);
}
