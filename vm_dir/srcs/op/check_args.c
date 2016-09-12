/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:52:05 by mblet             #+#    #+#             */
/*   Updated: 2016/09/12 12:34:21 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool	check_args(t_arg_type op, char *ptr)
{
	int		i;

	i = 0;
	(void)op;
	(void)ptr;
	while (i < 16)
	{
		//if (op == t->op[i].op_code)
			//t->op_func[i](ptr);
		++i;
	}
	return (true);
}
