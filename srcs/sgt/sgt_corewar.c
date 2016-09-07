/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_corewar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:16:20 by mblet             #+#    #+#             */
/*   Updated: 2016/09/07 17:42:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			s_ini_op(t_corewar *t)
{
	t->op[0] = {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0};
	t->op[1] = {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0};
	t->op[2] = {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0};
	t->op[3] = {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0};
	t->op[4] = {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0};
	t->op[5] = {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0};
	t->op[6] = {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0};
	t->op[7] = {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0};
	t->op[8] = {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1};
	t->op[9] = {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1};
	t->op[10] = {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25, "store index", 1, 1};
	t->op[11] = {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1};
	t->op[12] = {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0};
	t->op[13] = {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14, 50, "long load index", 1, 1};
	t->op[14] = {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1};
	t->op[15] = {"aff", 1, {T_REG}, 16, 2, "aff", 1, 0};
	t->op[16] = {0, 0, {0}, 0, 0, 0, 0, 0};
}

static void			s_ini_singleton(t_corewar *t)
{
	t->players = NULL;
	ft_bzero(t->ram, MEM_SIZE);
}

static t_corewar	**s_singleton(void)
{
	static t_corewar	*t = NULL;

	if (t == NULL)
	{
		s_ini_singleton(t);
		s_ini_op(t);
	}
	return (&t);
}

t_corewar			**sgt_addr_corewar(void)
{
	return (s_singleton());
}

t_corewar			*sgt_corewar(void)
{
	t_corewar	**t;

	t = sgt_addr_lemipc();
	return (*t);
}
