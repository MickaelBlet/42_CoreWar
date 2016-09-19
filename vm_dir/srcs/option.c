/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 00:50:16 by mblet             #+#    #+#             */
/*   Updated: 2016/09/19 01:09:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_check_file(int *i, char **argv)
{
	t_vm_file	*file;

	++(*i);
	if (ft_aisi(argv[*i]))
	{
		file = file_read(argv[(*i) + 1]);
		if (file == NULL)
		{
			ERR("corwar: error read file.");
			exit(EXIT_FAILURE);
		}
		file->id = ft_atoi(argv[*i]);
		++(*i);
		ft_lstd_push_front(&sgt_corewar()->files, file);
	}
	else
	{
		ERR("corwar: id \"%s\" not valid.", argv[*i]);
		exit(EXIT_FAILURE);
	}
}

static void		s_check_dump(int *i, char *arg)
{
	if (ft_aisi(arg))
	{
		sgt_corewar()->nbr_cycles = ft_atoi(arg);
		++(*i);
	}
	else
	{
		ERR("corwar: dump not valid.");
		exit(EXIT_FAILURE);
	}
}

t_bool			vm_option(int argc, char **argv)
{
	int		i;

	if (argc <= 2)
		return (false);
	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-dump"))
			s_check_dump(&i, argv[i + 1]);
		else if (ft_strequ(argv[i], "-n"))
			s_check_file(&i, argv);
		++i;
	}
}
