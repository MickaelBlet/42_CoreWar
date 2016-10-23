/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 00:50:16 by mblet             #+#    #+#             */
/*   Updated: 2016/10/21 22:43:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		s_find_free_id(void)
{
	t_listd		*list;
	t_file		*file;
	int			id;

	id = -1;
	while (id > -MAX_PLAYERS - 1)
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
		--id;
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

static t_bool	s_check_verbosity(char *arg)
{
	t_bool	ret;

	ret = false;
	if (ft_strequ(arg, "--lives") && (ret = true))
		sgt_corewar()->option.verbose.live = true;
	if (ft_strequ(arg, "--cycles") && (ret = true))
		sgt_corewar()->option.verbose.cycle = true;
	if (ft_strequ(arg, "--ops") && (ret = true))
		sgt_corewar()->option.verbose.op = true;
	if (ft_strequ(arg, "--deaths") && (ret = true))
		sgt_corewar()->option.verbose.death = true;
	if (ft_strequ(arg, "--moves") && (ret = true))
		sgt_corewar()->option.verbose.move = true;
	return (ret);
}

static void		s_check_dump(int *i, char *arg)
{
	if (ft_aisi(arg))
	{
		sgt_corewar()->option.dump = ft_atoi(arg);
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

	if (argc <= 1)
	{
		ft_printf("Usage: %s\n", MSG_USAGE);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-d"))
			s_check_dump(&i, argv[i + 1]);
		else if (ft_strequ(argv[i], "-n"))
			file_check(&i, argv);
		else if (ft_strequ(argv[i], "-g"))
			sgt_corewar()->option.graphic = true;
		else if (s_check_verbosity(argv[i]) == false)
			s_check_file_without_id(argv[i]);
		++i;
	}
}
