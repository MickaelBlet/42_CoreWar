/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_code_to_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 10:08:31 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 22:30:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static int	s_to_type(unsigned char b)
{
	if (b & 1)
	{
		if ((b >> 1) & 1)
			return (T_IND);
		else
			return (T_REG);
	}
	else if (b & 2)
		return (T_DIR);
	else
		return (0);
}

void		byte_code_to_type(int (*t)[4], unsigned char b)
{
	(*t)[3] = s_to_type(b >> 0);
	(*t)[2] = s_to_type(b >> 2);
	(*t)[1] = s_to_type(b >> 4);
	(*t)[0] = s_to_type(b >> 6);
}
