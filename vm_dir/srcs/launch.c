/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:14:23 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 13:35:39 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_bool	s_mutex_init(void)
{
	if (pthread_mutex_init(&sgt_corewar()->mutex, NULL) < 0)
		return (false);
	return (true);
}

void			launch(void)
{
	DGL;
	if (s_mutex_init() == false)
	{
		ERR("corwar: mlx mutex error.");
		exit(EXIT_FAILURE);
	}
	if (pthread_create(&sgt_corewar()->thread, NULL,
				&thread_vm, (void *)sgt_corewar()) < 0)
	{
		ERR("corwar: pthread creat error.");
		exit(EXIT_FAILURE);
	}
}
