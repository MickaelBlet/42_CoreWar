/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 00:50:16 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 15:43:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		s_find_free_id(void)
{
	t_listd		*list;
	t_file		*file;
	int			id;

	id = 0;
	while (id < MAX_PLAYERS)
	{
		list = sgt_corewar()->files;
		while (list)
		{
			file = list->data;
			if (file->id == id)
				break ;
			list = list->next;
		}
		if (list == NULL)
			return (id);
		++id;
	}
	ERR("corewar: max player.");
	exit(EXIT_FAILURE);
}

static void		s_check_file_without_id(char *arg)
{
	t_file	*file;

	file = file_read(arg);
	if (file == NULL)
	{
		ERR("corewar: error read file.");
		exit(EXIT_FAILURE);
	}
	file->id = s_find_free_id();
	ft_lstd_push_front(&sgt_corewar()->files, file);
}

static void		s_check_dump(int *i, char *arg)
{
	if (ft_aisi(arg))
	{
		sgt_corewar()->nbr_cycles_limit = ft_atoi(arg);
		++(*i);
	}
	else
	{
		ERR("corewar: dump not valid.");
		exit(EXIT_FAILURE);
	}
}

void			option(int argc, char **argv)
{
	int		i;

	if (argc <= 2)
	{
		ft_printf("Usage: %s\n", MSG_USAGE);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-dump"))
			s_check_dump(&i, argv[i + 1]);
		else if (ft_strequ(argv[i], "-n"))
			file_check(&i, argv);
		else
			s_check_file_without_id(argv[i]);
		++i;
	}
}
