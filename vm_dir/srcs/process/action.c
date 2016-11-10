/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:18:18 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 02:46:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_func(t_process *process, int type[4], int arg[4], int i_type)
{
	if (check_type_args(process->op, type, arg) == true)
	{
		verbose_op(process, type, arg);
		func_tab(process->op.op_code - 1)(process, type, arg);
	}
	if (process->op.op_code != 9 || process->carry == 0)
		verbose_move(process, i_type);
	process->pc = (process->pc + i_type) % MEM_SIZE;
	process->in_action = false;
}

static void		s_op_action(t_process *process, t_op op)
{
	int		type[4];
	int		arg[4];
	int		i;
	int		i_type;

	ft_bzero(type, sizeof(type));
	ft_bzero(arg, sizeof(arg));
	type[0] = T_DIR;
	i_type = (op.has_pcode) ? 2 : 1;
	if (op.has_pcode)
		byte_code_to_type(&type, get_reg_value(process->pc + 1));
	i = 0;
	while (i < op.nb_args)
	{
		arg[i] = get_value_from_type(process->pc + i_type,
				type[i], op.has_idx);
		i_type += (type[i] == T_REG) ? 1 : 0;
		i_type += (type[i] == T_IND) ? 2 : 0;
		i_type += (type[i] == T_DIR && op.has_idx) ? 2 : 0;
		i_type += (type[i] == T_DIR && !op.has_idx) ? 4 : 0;
		++i;
	}
	s_func(process, type, arg, i_type);
}

static t_bool	s_new_op(t_process *process)
{
	int		op;

	if (process->op_cycle == 0 && process->in_action == true)
		return (false);
	if (process->op_cycle > 0 && process->in_action == true)
		return (true);
	op = sgt_corewar()->ram[process->pc].data - 1;
	if (op_tab(op).op_code != 0)
	{
		process->op = op_tab(op);
		process->op_cycle = op_tab(op).nb_cycles - 1;
		process->in_action = true;
		return (true);
	}
	process->pc = (process->pc + 1) % MEM_SIZE;
	process->in_action = false;
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
	s_op_action(process, process->op);
}
