/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:17:57 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 16:52:50 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_color_init(void)
{
	sgt_mlx()->color[0] = 0xFFFFFF;
	sgt_mlx()->color[1] = 0xA00000;
	sgt_mlx()->color[2] = 0x00A000;
	sgt_mlx()->color[3] = 0xA0A000;
	sgt_mlx()->color[4] = 0x0000A0;
	sgt_mlx()->color[5] = 0xA000A0;
	sgt_mlx()->color[6] = 0x00A0A0;
	sgt_mlx()->color[7] = 0xA00000 - 0x300000;
	sgt_mlx()->color[8] = 0x00A000 - 0x003000;
	sgt_mlx()->color[9] = 0xA0A000 - 0x303000;
	sgt_mlx()->color[10] = 0x0000A0 - 0x000030;
	sgt_mlx()->color[11] = 0xA000A0 - 0x300030;
	sgt_mlx()->color[12] = 0x00A0A0 - 0x003030;
	sgt_mlx()->color[13] = 0xA00000 - 0x600000;
	sgt_mlx()->color[14] = 0x00A000 - 0x006000;
	sgt_mlx()->color[15] = 0xA0A000 - 0x606000;
	sgt_mlx()->color[16] = 0x0000A0 - 0x000060;
	sgt_mlx()->color[17] = 0xA000A0 - 0x600060;
	sgt_mlx()->color[18] = 0x00A0A0 - 0x006060;
}

static t_bool	s_hook_init(void)
{
	t_vm_mlx	*mlx;

	libx_func_key(LIBX_KEY_ESC, LIBX_KEY_PRESS, &vm_press_key_esc);
	libx_func_key(LIBX_KEY_C, LIBX_KEY_RELEASE, &vm_release_key_c);
	mlx = sgt_mlx();
	mlx_expose_hook(mlx->win, &vm_mlx_loop_hook, mlx);
	mlx_loop_hook(mlx->mlx, &vm_mlx_loop_hook, mlx);
	mlx_hook(mlx->win, 2, (1L << 0), &libx_hook_key_press, mlx);
	mlx_hook(mlx->win, 3, (1L << 1), &libx_hook_key_release, mlx);
	mlx_hook(mlx->win, 6, (1L << 6), &vm_mlx_mouse_motion, mlx);
	return (true);
}

static t_bool	s_img_init(void)
{
	t_vm_mlx	*mlx;

	mlx = sgt_mlx();
	mlx->img_font = libx_xpm_file_to_image(mlx->mlx, VM_PATH_FONT);
	mlx->img_memory = libx_new_image(mlx->mlx,
			VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH,
			MEM_SIZE / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT);
	mlx->img_info = libx_new_image(mlx->mlx,
			VM_INFO_WIDTH, VM_WIN_HEIGHT);
	mlx->background_memory = (unsigned char *)malloc(mlx->img_memory->width * \
			mlx->img_memory->height * \
			(mlx->img_memory->bits_per_pixel >> 3) + 1);
	mlx->background_info = (unsigned char *)malloc(mlx->img_info->width * \
			mlx->img_info->height * \
			(mlx->img_info->bits_per_pixel >> 3) + 1);
	if (mlx->img_font == NULL
		|| mlx->img_memory == NULL || mlx->img_info == NULL
		|| mlx->background_memory == NULL || mlx->background_info == NULL)
		return (false);
	return (true);
}

static t_bool	s_win_init(void)
{
	sgt_mlx()->win = ft_mlx_new_window(sgt_mlx()->mlx, 0, 0,
			VM_WIN_WIDTH, VM_WIN_HEIGHT, "corewar");
	if (sgt_mlx()->win == NULL)
		return (false);
	s_color_init();
	return (true);
}

void			vm_mlx_init(void)
{
	sgt_mlx()->mlx = mlx_init();
	if (sgt_mlx()->mlx == NULL
		|| s_win_init() == false
		|| s_img_init() == false
		|| s_hook_init() == false)
	{
		ft_dprintf(STDERR_FILENO, "init mlx.\n");
		exit(EXIT_FAILURE);
	}
}
