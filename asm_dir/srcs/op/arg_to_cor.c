/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 00:59:33 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 02:33:24 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_set_4byte_value(char *cor, unsigned int n)
{
	cor[0] = (unsigned char)(n >> 0x18);
	cor[1] = (unsigned char)(n >> 0x10);
	cor[2] = (unsigned char)(n >> 0x08);
	cor[3] = (unsigned char)(n >> 0x00);
}

static void		s_set_2byte_value(char *cor, unsigned short n)
{
	cor[0] = (unsigned char)(n >> 0x08);
	cor[1] = (unsigned char)(n >> 0x00);
}

static void		s_lab_to_cor(t_line *line, t_arg *arg)
{
	char	*cor;
	int		i;

	i = (arg->data[0] == '%') ? 2 : 1;
	if (label_check_same(arg->data + i) == true)
		return (error_print(*arg, ERR_OP_LAB_NOT_FOUND));
	arg->type -= T_LAB;
	cor = sgt_asm()->cor.data + arg->index_cor;
	if (arg->type == T_DIR && !line->op.has_idx)
		s_set_4byte_value(cor, label_get_addr(line->index_cor, arg->data + i));
	else
		s_set_2byte_value(cor, label_get_addr(line->index_cor, arg->data + i));
}

void			op_arg_to_cor(t_line *line, t_arg *arg)
{
	char	*cor;

	cor = sgt_asm()->cor.data + arg->index_cor;
	if (arg->type & T_LAB)
		s_lab_to_cor(line, arg);
	else if (arg->type == T_REG)
		*cor = (unsigned char)ft_atoi(arg->data + 1);
	else if (arg->type == T_DIR && !line->op.has_idx)
		s_set_4byte_value(cor, ft_atoi(arg->data + 1));
	else if (arg->type == T_DIR)
		s_set_2byte_value(cor, ft_atoi(arg->data + 1));
	else if (arg->type == T_IND)
		s_set_2byte_value(cor, ft_atoi(arg->data));
}
