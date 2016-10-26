/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 02:06:15 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 02:16:52 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	int		i;

	i = 0;
	ft_printf("0x%04x : ", i);
	while (i < CHAMP_MAX_SIZE)
	{
		s_convert_byte_to_hex(hex, sgt_asm()->cor.data[i]);
		ft_putstr(hex);
		++i;
		if (i % 2 == 0)
			ft_putchar(' ');
		if (i % 16 == 0)
		{
			ft_putchar('\n');
			if (i < MEM_SIZE)
				ft_printf("0x%04x : ", i);
		}
	}
}
