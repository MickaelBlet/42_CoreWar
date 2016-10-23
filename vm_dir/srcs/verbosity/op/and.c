/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:46:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 00:36:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_and(t_process *process, int type[4], int arg[4])
{
	char	str[2][256];

	if (type[0] == T_REG)
		ft_sprintf(str[0], "r%i", arg[0]);
	else
		ft_sprintf(str[0], "%i", arg[0]);
	if (type[1] == T_REG)
		ft_sprintf(str[1], "r%i", arg[1]);
	else
		ft_sprintf(str[1], "%i", arg[1]);
	ft_printf("P %4lu | %s %s %s r%i\n",
			process->uid, process->op.name,
			str[0], str[1], arg[2]);
}
