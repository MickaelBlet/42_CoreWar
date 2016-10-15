/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 16:53:28 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 16:59:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		vm_mlx_mouse_motion(int x, int y, t_vm_mlx *mlx)
{
	(void)mlx;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	return (1);
}
