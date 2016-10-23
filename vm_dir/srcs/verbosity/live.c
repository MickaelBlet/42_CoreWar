/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:49:58 by mblet             #+#    #+#             */
/*   Updated: 2016/10/21 22:15:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_live(int id, char *name)
{
	if (sgt_corewar()->option.verbose.live == false)
		return ;
	ft_printf("Player %i (%s) is said to be alive\n", id, name);
}
