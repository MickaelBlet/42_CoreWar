/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:05:19 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 23:16:03 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*vm_mlx_op_add(int pc, int type[4], int arg[4])
{
	char	*ret;

	(void)type;
	(void)pc;
	ret = NULL;
	if (arg[0] > 0 && arg[0] <= REG_NUMBER
		&& arg[1] > 0 && arg[1] <= REG_NUMBER
		&& arg[2] > 0 && arg[2] <= REG_NUMBER)
	{
		ft_asprintf(&ret, "*r%i = *r%i + *r%i", arg[2], arg[0], arg[1]);
	}
	return (ret);
}
