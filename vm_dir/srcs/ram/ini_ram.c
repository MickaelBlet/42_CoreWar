/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_ram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:31:06 by mblet             #+#    #+#             */
/*   Updated: 2016/10/21 23:28:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_file_merge(t_file *file, size_t index, int id)
{
	size_t	i;

	i = 0;
	while (i < file->header->prog_size)
	{
		sgt_corewar()->ram[index].data = file->data[sizeof(t_header) + i];
		sgt_corewar()->ram[index].color_id = id;
		sgt_corewar()->ram[index].modified_cycle = -100;
		sgt_corewar()->ram[index].live = 0;
		++index;
		++i;
	}
}

static void		s_place_file_and_creat_pc(void)
{
	t_listd		*list_files;
	t_file		*file;
	size_t		list_size;
	size_t		id;
	size_t		index;

	list_size = ft_lstd_size(sgt_corewar()->files);
	list_files = sgt_corewar()->files;
	id = 1;
	while (list_files)
	{
		file = list_files->data;
		index = (id - 1) * (MEM_SIZE / list_size);
		s_file_merge(file, index, id);
		ft_lstd_push_front(&sgt_corewar()->process,
				process_creat(index, file->id, id));
		ft_lstd_push_front(&sgt_corewar()->players,
				player_creat(file, id));
		list_files = list_files->next;
		++id;
	}
}

static void		s_sort_files(void)
{
	size_t		len;
	t_listd		*list;
	t_file		*tmp;
	t_file		*file1;
	t_file		*file2;

	len = ft_lstd_size(sgt_corewar()->files);
	while (len > 0)
	{
		list = sgt_corewar()->files;
		while (list->next)
		{
			file1 = list->data;
			file2 = list->next->data;
			if (file1->id < file2->id)
			{
				tmp = list->data;
				list->data = list->next->data;
				list->next->data = tmp;
			}
			list = list->next;
		}
		--len;
	}
}

void			ini_ram(void)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		sgt_corewar()->ram[i].data = 0;
		sgt_corewar()->ram[i].color_id = 0;
		sgt_corewar()->ram[i].modified_cycle = -100;
		sgt_corewar()->ram[i].live = 0;
		++i;
	}
	s_sort_files();
	ft_printf("Introducing contestants...\n");
	s_place_file_and_creat_pc();
}
