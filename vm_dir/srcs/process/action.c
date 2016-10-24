/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:18:18 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 16:57:17 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_func(t_process *process)
{
	int		type[4];
	int		val[4];
	int		index_type;

	ft_bzero(type, sizeof(int) * 4);
	ft_bzero(val, sizeof(int) * 4);
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
	verbose_op(process, type, val);
	func_tab(process->op.op_code - 1)(process, type, val);
	if (process->op.op_code != 9)
		verbose_move(process, index_type);
	process->pc = (process->pc + index_type) % MEM_SIZE;
	process->op = op_tab(16);
}

static void		s_func_pcode(t_process *process)
{
	int		type[4];
	int		val[4];
	int		i;
	int		index_type;

	ft_bzero(type, sizeof(int) * 4);
	ft_bzero(val, sizeof(int) * 4);
	byte_code_to_type(&type,
			sgt_corewar()->ram[(process->pc + 1) % MEM_SIZE].data);
	i = 0;
	index_type = 2;
	while (i < process->op.nb_args)
	{
		val[i] = get_value_from_type(process->pc + index_type,
				type[i], process->op.has_idx);
		index_type = (type[i] == T_REG) ? index_type + 1 : index_type;
		if ((type[i] == T_DIR && process->op.has_idx == 1))
			index_type += 2;
		else if (type[i] == T_DIR)
			index_type += 4;
		else if (type[i] == T_IND)
			index_type += 2;
		++i;
	}
	if (check_type_args(process->op, type, val) == true)
	{
		verbose_op(process, type, val);
		func_tab(process->op.op_code - 1)(process, type, val);
	}
	verbose_move(process, index_type);
	process->pc = (process->pc + index_type) % MEM_SIZE;
	process->op = op_tab(16);
}

static t_bool	s_new_op(t_process *process)
{
	int		op;

	if (process->op_cycle == 0 && process->op.name != 0)
		return (false);
	if (process->op_cycle > 0 && process->op.name != 0)
		return (true);
	op = sgt_corewar()->ram[process->pc].data - 1;
	if (op_tab(op).op_code != 0)
	{
		process->op = op_tab(op);
		process->op_cycle = op_tab(op).nb_cycles - 1;
		return (true);
	}
	process->op = op_tab(16);
	process->pc = (process->pc + 1) % MEM_SIZE;
	return (true);
}

void			process_action(t_process *process)
{
	if (process == NULL)
		return ;
	if (process->op_cycle > 0)
		process->op_cycle -= 1;
	if (s_new_op(process) == true)
		return ;
	if (process->op.has_pcode)
		return (s_func_pcode(process));
	else
		s_func(process);
}
