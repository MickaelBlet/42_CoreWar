/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 10:51:03 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 21:36:33 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*vm_mlx_thread_memory(void *e)
{
	(void)e;
	while (true)
	{
		pthread_mutex_lock(&sgt_mlx()->mutex_memory);
		vm_mlx_draw_memory();
		pthread_mutex_unlock(&sgt_mlx()->mutex_memory);
		usleep(100);
	}
	return (NULL);
}
