/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 22:15:08 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 12:48:41 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_convert_byte_to_hex(char *ret, unsigned char byte)
{
	ret[0] = (byte / 0x10) % 0x10;
	ret[1] = byte % 0x10;
	ret[0] += (ret[0] > 9) ? 'a' - 10 : '0';
	ret[1] += (ret[1] > 9) ? 'a' - 10 : '0';
	ret[2] = ' ';
	ret[3] = '\0';
}

void			verbose_move(t_process *process, int jump)
{
	int		i;
	int		index;
	char	str[1024];

	if (sgt_corewar()->option.verbose.move == false)
		return ;
	i = ft_sprintf(str, "ADV %u (0x%04x -> 0x%04x) ", jump, (int)process->pc,
			(int)(process->pc + jump));
	index = 0;
	while (index < jump)
	{
		s_convert_byte_to_hex(str + i,
				sgt_corewar()->ram[(process->pc + index) % MEM_SIZE].data);
		++index;
		i += 3;
	}
	ft_printf("%s\n", str);
}
