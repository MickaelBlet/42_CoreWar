/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:55:11 by mblet             #+#    #+#             */
/*   Updated: 2016/10/21 21:12:34 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_cycle(void)
{
	if (sgt_corewar()->option.verbose.cycle == false)
		return ;
	ft_printf("It is now cycle %lli\n", sgt_corewar()->cycle);
}
