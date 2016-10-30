/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 00:59:33 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 14:01:00 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_set_4byte_value(char *cor, int index, unsigned int n)
{
	cor[(index + 0) % CHAMP_MAX_SIZE] = (unsigned char)(n >> 0x18);
	cor[(index + 1) % CHAMP_MAX_SIZE] = (unsigned char)(n >> 0x10);
	cor[(index + 2) % CHAMP_MAX_SIZE] = (unsigned char)(n >> 0x08);
	cor[(index + 3) % CHAMP_MAX_SIZE] = (unsigned char)(n >> 0x00);
}

static void		s_set_2byte_value(char *cor, int index, unsigned short n)
{
	cor[(index + 0) % CHAMP_MAX_SIZE] = (unsigned char)(n >> 0x08);
	cor[(index + 1) % CHAMP_MAX_SIZE] = (unsigned char)(n >> 0x00);
}

static void		s_lab_to_cor(t_line *line, t_arg *arg)
{
	int		i;

	i = (arg->data[0] == '%') ? 2 : 1;
	if (label_check_name(arg->data + i) == false)
		return (error_print(*arg, ERR_LAB_NAME));
	if (label_check_same(arg->data + i) == true)
		return (error_print(*arg, ERR_OP_LAB_NOT_FOUND));
	arg->type -= T_LAB;
	if (arg->type == T_DIR && !line->op.has_idx)
		s_set_4byte_value(sgt_asm()->cor.data, arg->index_cor,
				label_get_addr(line->index_cor, arg->data + i));
	else
		s_set_2byte_value(sgt_asm()->cor.data, arg->index_cor,
				label_get_addr(line->index_cor, arg->data + i));
}

void			op_arg_to_cor(t_line *line, t_arg *arg)
{
	if (arg->type & T_LAB)
		s_lab_to_cor(line, arg);
	else if (arg->type == T_REG)
		sgt_asm()->cor.data[arg->index_cor % CHAMP_MAX_SIZE] =
			(unsigned char)ft_atoi(arg->data + 1);
	else if (arg->type == T_DIR && !line->op.has_idx && ft_aisi(arg->data + 1))
		s_set_4byte_value(sgt_asm()->cor.data, arg->index_cor,
				ft_atoi(arg->data + 1));
	else if (arg->type == T_DIR && !line->op.has_idx)
		s_set_4byte_value(sgt_asm()->cor.data, arg->index_cor,
				ft_ahtoi(arg->data + 1));
	else if (arg->type == T_DIR && ft_aisi(arg->data + 1))
		s_set_2byte_value(sgt_asm()->cor.data, arg->index_cor,
				ft_atoi(arg->data + 1));
	else if (arg->type == T_DIR)
		s_set_2byte_value(sgt_asm()->cor.data, arg->index_cor,
				ft_ahtoi(arg->data + 1));
	else if (arg->type == T_IND && ft_aisi(arg->data))
		s_set_2byte_value(sgt_asm()->cor.data, arg->index_cor,
				ft_atoi(arg->data));
	else if (arg->type == T_IND)
		s_set_2byte_value(sgt_asm()->cor.data, arg->index_cor,
				ft_ahtoi(arg->data));
}
