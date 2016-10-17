/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:54:44 by mblet             #+#    #+#             */
/*   Updated: 2016/10/16 11:12:01 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		vm_mlx_loop_hook(t_vm_mlx *mlx)
{
	//if (pthread_mutex_trylock(&mlx->mutex_memory) == 0)
	//{
		pthread_mutex_lock(&mlx->mutex_memory);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_memory->img_ptr,
				VM_INFO_WIDTH, 5);
		pthread_mutex_unlock(&mlx->mutex_memory);
	//}
	if (pthread_mutex_trylock(&mlx->mutex_info) == 0)
	{
		//pthread_mutex_lock(&mlx->mutex_info);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_info->img_ptr,
				0, 0);
		pthread_mutex_unlock(&mlx->mutex_info);
	}
	return (0);
}
