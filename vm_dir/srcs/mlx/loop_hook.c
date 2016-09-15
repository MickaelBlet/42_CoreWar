/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:54:44 by mblet             #+#    #+#             */
/*   Updated: 2016/09/15 12:58:29 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		vm_mlx_loop_hook(void *mlx)
{
	(void)mlx;
	mlx_put_image_to_window(sgt_mlx()->mlx, sgt_mlx()->win,
			sgt_mlx()->main->img_ptr, 0, 0);
	return (0);
}
