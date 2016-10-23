/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 20:21:20 by mblet             #+#    #+#             */
/*   Updated: 2016/10/23 20:26:18 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool	check_type_args(t_process *process, int type[4], int arg[4])
{
	int		i;

	i = 0;
	while (i < process->op.nb_args)
	{
		if (!(process->op.type_args[i] & type[i]))
			return (false);
		if (type[i] == T_REG && (arg[i] <= 0 || arg[i] > REG_NUMBER))
			return (false);
		++i;
	}
	return (true);
}
