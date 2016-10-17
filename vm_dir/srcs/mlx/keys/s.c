/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 16:31:50 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 19:47:48 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** STEP BY STEP
*/
void	vm_press_key_s(t_vm_mlx *mlx)
{
	(void)mlx;
	pthread_mutex_unlock(&sgt_corewar()->mutex);
	pthread_mutex_lock(&sgt_corewar()->mutex);
}
