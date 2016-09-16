/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:40:07 by mblet             #+#    #+#             */
/*   Updated: 2016/09/15 20:09:11 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_print(void)
{
	size_t	i;
	char	*str;

	i = 0;
	libx_image_fill(sgt_mlx()->main, 0x1111111);
	while (i < MEM_SIZE)
	{
		str = NULL;
		ft_asprintf(&str, "%02x", (unsigned char)sgt_corewar()->ram[i]);
		LIBX_STRING_TO_IMAGE(sgt_mlx()->main, sgt_mlx()->font,
				str, i % 64 * 20 + 20, i / 64 * 18 + 20, 0xFFFFFF);
		++i;
	}
}
