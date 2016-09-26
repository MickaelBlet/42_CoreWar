/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 01:53:52 by mblet             #+#    #+#             */
/*   Updated: 2016/09/26 09:51:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_op(t_player *player)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		if (op_tab(i).op_code == player->pc->data && func_tab(i) != NULL)
		{
			DG("%s %s", op_tab(i).name, op_tab(i).description);
			func_tab(i)(player);
			return ;
		}
		++i;
	}
}
