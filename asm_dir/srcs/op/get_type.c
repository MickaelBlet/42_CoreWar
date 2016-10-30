/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:58:32 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 13:40:08 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	s_get_registre(t_op op, char *str)
{
	int		index_registre;

	(void)op;
	if (ft_aisi(str + 1) == false)
		return (0);
	index_registre = ft_atoi(str + 1);
	if (index_registre < 1 || index_registre > REG_NUMBER)
		return (0);
	sgt_asm()->index_cor += 1;
	return (T_REG);
}

static int	s_get_direct(t_op op, char *str)
{
	int		ret;

	ret = 0;
	if (str[1] == ':')
		ret = T_LAB;
	else if (ft_aisi(str + 1) == false && ft_aish(str + 1) == false)
		return (0);
	if (op.has_idx)
		sgt_asm()->index_cor += 2;
	else
		sgt_asm()->index_cor += 4;
	return (ret + T_DIR);
}

static int	s_get_label(t_op op, char *str)
{
	(void)op;
	(void)str;
	sgt_asm()->index_cor += 2;
	return (T_LAB + T_IND);
}

int			op_get_type(t_op op, char *str)
{
	if (str == NULL)
		return (0);
	else if (str[0] == 'r')
		return (s_get_registre(op, str));
	else if (str[0] == '%')
		return (s_get_direct(op, str));
	else if (str[0] == ':')
		return (s_get_label(op, str));
	else if (ft_aisi(str) || ft_aish(str))
	{
		sgt_asm()->index_cor += 2;
		return (T_IND);
	}
	return (0);
}
