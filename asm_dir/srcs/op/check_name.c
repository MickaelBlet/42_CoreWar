/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 21:38:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 21:41:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool		op_check_name(char *name)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strequ(name, op_tab(i).name))
			return (true);
		++i;
	}
	return (false);
}
