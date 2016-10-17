/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:06:01 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 23:16:41 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		*s_error(char *ret)
{
	ft_asprintf(&ret, "error");
	return (ret);
}

char			*vm_mlx_op_and(int pc, int type[4], int arg[4])
{
	char	*ret;

	(void)pc;
	ret = NULL;
	if (arg[2] > 0 && arg[2] <= REG_NUMBER)
		ft_asprintf(&ret, "*r%i = ", arg[2]);
	else
		return (s_error(ret));
	if (type[0] == T_REG && arg[0] > 0 && arg[0] <= REG_NUMBER)
		ft_asprintf(&ret, "%s*r%i & ", ret, arg[0]);
	else if (type[0] != T_REG)
		ft_asprintf(&ret, "%s%x & ", ret, arg[0]);
	else
		return (s_error(ret));
	if (type[1] == T_REG && arg[1] > 0 && arg[1] <= REG_NUMBER)
		ft_asprintf(&ret, "%s*r%i", ret, arg[1]);
	else if (type[1] != T_REG)
		ft_asprintf(&ret, "%s%x", ret, arg[1]);
	else
		return (s_error(ret));
	return (ret);
}
