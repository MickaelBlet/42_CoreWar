/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_memory_from_pc.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 12:36:06 by mblet             #+#    #+#             */
/*   Updated: 2016/10/18 10:38:19 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_get_position_memory_from_pc(int pc, int *x, int *y)
{
	*x = pc % VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH + 2;
	*y = pc / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT;
}
