/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:04:28 by mblet             #+#    #+#             */
/*   Updated: 2016/10/16 23:51:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_basic_run(void)
{
	while (sgt_corewar()->run)
	{
		cycle();
	}
}

void			corewar(int argc, char **argv)
{
	option(argc, argv);
	ini_ram();
	if (sgt_corewar()->graphic)
	{
		vm_mlx_init();
		vm_mlx_launch();
		thread_launch();
		mlx_loop(sgt_mlx()->mlx);
	}
	else
	{
		s_basic_run();
	}
}
