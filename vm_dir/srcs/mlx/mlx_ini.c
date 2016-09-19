/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:17:57 by mblet             #+#    #+#             */
/*   Updated: 2016/09/19 00:25:21 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include <mlx.h>

static t_bool	s_hook_init(void)
{
	libx_func_key(LIBX_KEY_ESC, LIBX_KEY_PRESS, &vm_press_key_esc);
	mlx_expose_hook(sgt_mlx()->win, &vm_mlx_loop_hook, sgt_mlx());
	mlx_loop_hook(sgt_mlx()->mlx, &vm_mlx_loop_hook, sgt_mlx());
	mlx_hook(sgt_mlx()->win, 2, (1L << 0), &libx_hook_key_press, sgt_mlx());
	mlx_hook(sgt_mlx()->win, 3, (1L << 1), &libx_hook_key_release, sgt_mlx());
	vm_mlx_print();
	return (true);
}

t_bool			vm_mlx_init(void)
{
	sgt_mlx()->mlx = mlx_init();
	if (sgt_mlx()->mlx == NULL)
		return (false);
	sgt_mlx()->win = ft_mlx_new_window(sgt_mlx()->mlx, 0, 0,
			VM_WIN_WIDTH, VM_WIN_HEIGHT, "corewar");
	sgt_mlx()->img_main = libx_new_image(sgt_mlx()->mlx,
			VM_WIN_WIDTH, VM_WIN_HEIGHT);
	sgt_mlx()->img_font = libx_xpm_file_to_image(sgt_mlx()->mlx, VM_FONT_PATH);
	sgt_mlx()->img_ram = libx_new_image(sgt_mlx()->mlx, VM_WIN_WIDTH - 200,
			MEM_SIZE / 64 * 18);
	if (sgt_mlx()->win == NULL
		|| sgt_mlx()->img_main == NULL
		|| sgt_mlx()->img_font == NULL
		|| sgt_mlx()->img_ram == NULL
		|| s_hook_init() == false)
		return (false);
	return (true);
}
