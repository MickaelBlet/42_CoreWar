/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:49:32 by mblet             #+#    #+#             */
/*   Updated: 2016/12/21 20:51:22 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_basic_run(void)
{
	while (sgt_corewar()->run)
		cycle();
	win();
}

void			corewar(int argc, char **argv)
{
	option(argc, argv);
	ini_ram();
	if (sgt_corewar()->option.graphic)
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
