/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 09:22:20 by mblet             #+#    #+#             */
/*   Updated: 2016/09/15 17:19:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include <libft.h>

static t_bool	s_check_args(int argc, char **argv)
{
	int		i;

	if (argc <= 2)
		return (false);
	i = 0;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-dump"))
		{
			++i;
			if (ft_aisi(argv[i]))
				sgt_corewar()->nbr_cycles = ft_atoi(argv[i]);
		}
		else if (ft_strequ(argv[i], "-n"))
		{
			++i;
			if (ft_aisi(argv[i]))
				ft_lstd_push_front(&sgt_corewar()->players,
						player_creat(ft_atoi(argv[i]), argv[i + 1]));
		}
		++i;
	}
	return (true);
}

int				main(int argc, char **argv)
{
	if (s_check_args(argc, argv) == false)
		ft_printf("Usage: %s\n", MSG_USAGE);
	corewar();
	return (0);
}
