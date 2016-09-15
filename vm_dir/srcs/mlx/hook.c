/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:42:30 by mblet             #+#    #+#             */
/*   Updated: 2016/09/15 16:23:23 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_press_key_esc(void *mlx)
{
	(void)mlx;
	exit(EXIT_SUCCESS);
}

int		vm_hook_key(int key, t_vm_mlx *mlx)
{
	libx_hook_key(key, mlx);
	return (1);
}
