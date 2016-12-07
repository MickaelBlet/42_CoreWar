/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suppr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 09:31:37 by mblet             #+#    #+#             */
/*   Updated: 2016/12/06 10:44:19 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_reload_file(void)
{
	t_corewar	*t;

	t = sgt_corewar();
	t->cycle = 0;
	t->cycle_to_die = CYCLE_TO_DIE;
	t->cycle_check = 0;
	t->last_cycle_check = 0;
	t->nb_process = 0;
	ini_ram();
}

static void		s_delete_all_player_process(void)
{
	ft_lstd_clear(&sgt_corewar()->players, &free);
	ft_lstd_clear(&sgt_corewar()->process, &free);
}

void			vm_press_key_suppr(t_vm_mlx *mlx)
{
	(void)mlx;
	if (sgt_corewar()->cycle == 0)
		return ;
	pthread_mutex_unlock(&sgt_corewar()->mutex);
	pthread_mutex_lock(&sgt_corewar()->mutex);
	ft_printf("Reset Corewar !\n");
	pthread_mutex_lock(&sgt_mlx()->mutex_info);
	pthread_mutex_lock(&sgt_mlx()->mutex_memory);
	sgt_mlx()->pause = true;
	s_delete_all_player_process();
	s_reload_file();
	if (sgt_corewar()->run == false)
	{
		pthread_mutex_unlock(&sgt_corewar()->mutex);
		if (pthread_create(&sgt_corewar()->thread, NULL,
					&thread_vm, (void *)sgt_corewar()) < 0)
		{
			ERR("corwar: pthread creat error.");
			exit(EXIT_FAILURE);
		}
		sgt_corewar()->run = true;
	}
	pthread_mutex_unlock(&sgt_mlx()->mutex_info);
	pthread_mutex_unlock(&sgt_mlx()->mutex_memory);
}
