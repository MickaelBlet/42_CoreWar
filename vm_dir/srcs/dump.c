/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 02:25:26 by mblet             #+#    #+#             */
/*   Updated: 2016/10/16 03:25:34 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_convert_byte_to_hex(char *ret, unsigned char byte)
{
	ret[0] = (byte / 0x10) % 0x10;
	ret[1] = byte % 0x10;
	ret[0] += (ret[0] > 9) ? 'a' - 10 : '0';
	ret[1] += (ret[1] > 9) ? 'a' - 10 : '0';
	ret[2] = '\0';
}

void			dump(void)
{
	char	hex[3];
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		s_convert_byte_to_hex(hex, sgt_corewar()->ram[i].data);
		if (sgt_corewar()->ram[i].color_id > 0)
			ft_printf("{fg=%i}", sgt_corewar()->ram[i].color_id);
		ft_putstr(hex);
		ft_printf("{reset}");
		++i;
		if (i % 32 == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
	system("afplay /System/Library/Sounds/Basso.aiff&");
}
