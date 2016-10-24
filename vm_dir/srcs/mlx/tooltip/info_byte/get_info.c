/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:45:38 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 17:47:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_size_print(char *ret, int pc, int index_type)
{
	int		i;

	i = pc;
	ft_sprintf(ret, "%s\n%02x", ret, sgt_corewar()->ram[i]);
	++i;
	while (i < pc + index_type)
	{
		ft_sprintf(ret, "%s %02x", ret, sgt_corewar()->ram[i]);
		++i;
	}
}

static void		s_print(char *ret, t_op op, int type[4], int arg[4])
{
	int		i;

	i = 0;
	ft_sprintf(ret, "%s  ", op.name);
	while (i < op.nb_args)
	{
		if (type[i] == T_REG)
			ft_sprintf(ret, "%s r%i", ret, arg[i]);
		else
			ft_sprintf(ret, "%s %i", ret, arg[i]);
		++i;
	}
}

static void		s_func(char *ret, t_op op, int pc)
{
	int		type[4];
	int		arg[4];
	int		index_type;

	ft_bzero(type, sizeof(int) * 4);
	ft_bzero(arg, sizeof(int) * 4);
	index_type = 1;
	type[0] = op.type_args[0];
	arg[0] = get_value_from_type(pc + index_type, op.type_args[0], op.has_idx);
	index_type += (op.has_idx) ? 2 : 4;
	s_print(ret, op, type, arg);
	s_size_print(ret, pc, index_type);
}

static void		s_func_pcode(char *ret, t_op op, int pc)
{
	int		type[4];
	int		arg[4];
	int		i;
	int		index_type;

	ft_bzero(type, sizeof(int) * 4);
	ft_bzero(arg, sizeof(int) * 4);
	byte_code_to_type(&type, sgt_corewar()->ram[(pc + 1) % MEM_SIZE].data);
	i = 0;
	index_type = 2;
	while (i < op.nb_args)
	{
		arg[i] = get_value_from_type(pc + index_type, type[i], op.has_idx);
		index_type += (type[i] == T_REG) ? 1 : 0;
		index_type += (type[i] == T_IND) ? 2 : 0;
		index_type += (type[i] == T_DIR && op.has_idx) ? 2 : 0;
		index_type += (type[i] == T_DIR && !op.has_idx) ? 4 : 0;
		++i;
	}
	if (check_type_args(op, type, arg))
		s_print(ret, op, type, arg);
	else
		ft_sprintf(ret, "error !");
	s_size_print(ret, pc, index_type);
}

char			*vm_mlx_get_info_byte(t_op op, int pc)
{
	static char		ret[256];

	if (op.has_pcode)
		s_func_pcode(ret, op, pc);
	else
		s_func(ret, op, pc);
	return (ret);
}
