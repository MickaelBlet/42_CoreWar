/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:13:58 by mblet             #+#    #+#             */
/*   Updated: 2016/10/21 16:47:10 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		process_jump(t_process *process, int jump)
{
	process->pc = (process->pc + jump) % MEM_SIZE;
}
