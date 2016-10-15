/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:18:18 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 14:55:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_func(t_process *process)
{
	int		type[4];
	int		val[4];
	int		index_type;

	type[0] = 0;
	type[1] = 0;
	type[2] = 0;
	type[3] = 0;
	val[0] = 0;
	val[1] = 0;
	val[2] = 0;
	val[3] = 0;
	index_type = 1;
	val[0] = get_value_from_type((process->pc + index_type) % MEM_SIZE,
			process->op.type_args[0], process->op.has_idx);
	type[0] = T_DIR;
	if (process->op.has_idx == 1)
	{
		index_type += 2;
		val[0] = (short)val[0];
	}
	else
	{
		index_type += 4;
	}
	//DG("%i, %x, %x, %x", val[0], val[1], val[2], val[3]);
	func_tab(process->op.op_code - 1)(process, type, val);
	process->pc = (process->pc + index_type) % MEM_SIZE;
	process->op = op_tab(16);
}

static void		s_func_pcode(t_process *process)
{
	int		type[4];
	int		val[4];
	int		i;
	int		index_type;

	type[0] = 0;
	type[1] = 0;
	type[2] = 0;
	type[3] = 0;
	val[0] = 0;
	val[1] = 0;
	val[2] = 0;
	val[3] = 0;
	byte_code_to_type(&type,
			sgt_corewar()->ram[(process->pc + 1) % MEM_SIZE].data);
	i = 0;
	index_type = 2;
	while (i < process->op.nb_args)
	{
		if (!(process->op.type_args[i] & type[i]))
		{
			process->pc = (process->pc + 1) % MEM_SIZE;
			process->op = op_tab(16);
			return ;
		}
		if (process->op.op_code >= 3 && process->op.op_code <= 5
			&& type[i] == T_IND)
		{
			type[i] = T_DIR;
			process->op.has_idx = 1;
		}
		val[i] = get_value_from_type(process->pc + index_type,
				type[i], process->op.has_idx);
		index_type = (type[i] == T_REG) ? index_type + 1 : index_type;
		if ((type[i] == T_DIR && process->op.has_idx == 1))
			index_type += 2;
		else if (type[i] == T_DIR || type[i] == T_IND)
			index_type += 4;
		++i;
	}
	//DG("%x, %x, %x, %x", val[0], val[1], val[2], val[3]);
	func_tab(process->op.op_code - 1)(process, type, val);
	process->pc = (process->pc + index_type) % MEM_SIZE;
	process->op = op_tab(16);
}

static t_bool	s_new_op(t_process *process)
{
	int		i;

	if (process->op_cycle == 0 && process->op.name != 0)
		return (false);
	if (process->op_cycle > 0 && process->op.name != 0)
		return (true);
	i = 0;
	while (i < 16)
	{
		if (sgt_corewar()->ram[process->pc].data == op_tab(i).op_code)
		{
			//DG("code:%s", op_tab(i).name);
			process->op = op_tab(i);
			process->op_cycle = op_tab(i).nb_cycles;
			return (true);
		}
		++i;
	}
	process->op = op_tab(16);
	process->pc = (process->pc + 1) % MEM_SIZE;
	return (true);
}

void			process_action(t_process *process)
{
	//DG("info pc:\n\tindex=%i\n\top_code=%i\n\tnb_cycle=%i", process->pc, sgt_corewar()->ram[process->pc].data, process->op_cycle);
	if (process->op_cycle > 0)
		process->op_cycle -= 1;
	if (s_new_op(process) == true)
		return ;
	if (sgt_corewar()->ram[process->pc].data != process->op.op_code)
		return ((void)s_new_op(process));
	if (process->op.has_pcode)
		return (s_func_pcode(process));
	else
		s_func(process);
}
