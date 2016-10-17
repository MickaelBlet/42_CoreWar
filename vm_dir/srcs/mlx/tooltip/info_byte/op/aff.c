/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:08:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 23:16:12 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*vm_mlx_op_aff(int pc, int type[4], int arg[4])
{
	char	*ret;

	ret = NULL;
	(void)pc;
	(void)type;
	if (arg[0] > 0 && arg[0] <= REG_NUMBER)
	{
		ft_asprintf(&ret, "print \'*r%i\'", arg[0]);
	}
	return (ret);
}
