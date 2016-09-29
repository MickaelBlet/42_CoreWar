/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:16:13 by mblet             #+#    #+#             */
/*   Updated: 2016/09/28 16:24:40 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_check_if_free_id(int id)
{
	t_listd		*list;
	t_file		*file;

	list = sgt_corewar()->files;
	while (list)
	{
		file = list->data;
		if (file->id == id)
		{
			ERR("corewar: same id.");
			exit(EXIT_FAILURE);
		}
		list = list->next;
	}
}

void			vm_check_file(int *i, char **argv)
{
	t_file	*file;

	++(*i);
	if (ft_aisi(argv[*i]))
	{
		file = file_read(argv[(*i) + 1]);
		if (file == NULL)
		{
			ERR("corewar: error read file.");
			exit(EXIT_FAILURE);
		}
		file->id = ft_atoi(argv[*i]);
		s_check_if_free_id(file->id);
		++(*i);
		ft_lstd_push_front(&sgt_corewar()->files, file);
	}
	else
	{
		ERR("corewar: id \"%s\" not valid.", argv[*i]);
		exit(EXIT_FAILURE);
	}
}
