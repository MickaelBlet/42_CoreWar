/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_code_to_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 10:08:31 by mblet             #+#    #+#             */
/*   Updated: 2016/09/20 12:02:35 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	s_char_to_type(char *s)
{
	if (s[0] == '0' && s[1] == '0')
		return (0);
	if (s[0] == '0' && s[1] == '1')
		return (T_REG);
	if (s[0] == '1' && s[1] == '1')
		return (T_DIR);
	if (s[0] == '1' && s[1] == '0')
		return (T_LAB);
	return (0);
}

void		byte_code_to_type(int (*t)[4], unsigned char b)
{
	char	s[9];

	ft_bzero(s, 8);
	ft_bzero((*t), 4 * sizeof(int));
	ft_sprintf(s, "%08b", b);
	(*t)[0] = s_char_to_type(s);
	(*t)[1] = s_char_to_type(s + 2);
	(*t)[2] = s_char_to_type(s + 4);
	(*t)[3] = s_char_to_type(s + 6);
	DG("%i, %i, %i, %i", (*t)[0], (*t)[1], (*t)[2], (*t)[3]);
}
