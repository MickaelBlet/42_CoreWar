/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 10:53:27 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 15:23:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*vm_mlx_thread_info(void *e)
{
	(void)e;
	while (true)
	{
		pthread_mutex_lock(&sgt_mlx()->mutex_info);
		vm_mlx_draw_info();
		pthread_mutex_unlock(&sgt_mlx()->mutex_info);
		usleep(10000);
	}
	return (NULL);
}
