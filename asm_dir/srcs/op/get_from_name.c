/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:07:07 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 22:08:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	op_get_from_name(char *name)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strequ(name, op_tab(i).name))
			return (op_tab(i));
		++i;
	}
	return (op_tab(-1));
}
