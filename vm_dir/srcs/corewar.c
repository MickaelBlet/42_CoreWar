/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:04:28 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 14:03:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	corewar(int argc, char **argv)
{
	option(argc, argv);
	ini_ram();
	DGL;
	vm_mlx_init();
	DGL;
	vm_mlx_launch();
	DGL;
	launch();
	usleep(100000);
	mlx_loop(sgt_mlx()->mlx);
}
