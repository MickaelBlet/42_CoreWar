/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 12:35:30 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 21:23:33 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void		s_ini_op_tab2(t_op **t)
{
	(*t)[9] = (t_op){"ldi", 3,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1};
	(*t)[10] = (t_op){"sti", 3,
		{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1};
	(*t)[11] = (t_op){"fork", 1,
		{T_DIR}, 12, 800, "fork", 0, 1};
	(*t)[12] = (t_op){"lld", 2,
		{T_DIR | T_IND, T_REG}, 13, 10,
		"long load", 1, 0};
	(*t)[13] = (t_op){"lldi", 3,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1};
	(*t)[14] = (t_op){"lfork", 1,
		{T_DIR}, 15, 1000, "long fork", 0, 1};
	(*t)[15] = (t_op){"aff", 1,
		{T_REG}, 16, 2, "aff", 1, 0};
	(*t)[16] = (t_op){0, 0, {0}, 0, 0, 0, 0, 0};
}

static void		s_ini_op_tab(t_op **t)
{
	(*t)[0] = (t_op){"live", 1,
		{T_DIR}, 1, 10, "alive", 0, 0};
	(*t)[1] = (t_op){"ld", 2,
		{T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0};
	(*t)[2] = (t_op){"st", 2,
		{T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0};
	(*t)[3] = (t_op){"add", 3,
		{T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0};
	(*t)[4] = (t_op){"sub", 3,
		{T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0};
	(*t)[5] = (t_op){"and", 3,
		{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0};
	(*t)[6] = (t_op){"or", 3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0};
	(*t)[7] = (t_op){"xor", 3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0};
	(*t)[8] = (t_op){"zjmp", 1,
		{T_DIR}, 9, 20, "jump if zero", 0, 1};
	s_ini_op_tab2(t);
}

t_op			op_tab(int index)
{
	static t_op		*t = NULL;

	if (t == NULL)
	{
		if ((t = (t_op *)malloc(sizeof(t_op) * 17)) == NULL)
		{
			ERR("malloc: error.");
			exit(EXIT_FAILURE);
		}
		s_ini_op_tab(&t);
	}
	if (index >= 0 && index <= 15)
		return (t[index]);
	return (t[16]);
}
