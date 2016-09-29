/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_ram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:31:06 by mblet             #+#    #+#             */
/*   Updated: 2016/09/28 17:30:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_file_merge(t_file *file, t_byte *b, int id)
{
	size_t	i;

	i = 0;
	while (i < file->header->prog_size)
	{
		b->data = file->data[sizeof(t_header) + i];
		b->id = id;
		b->modified = false;
		b->live = false;
		++b;
		++i;
	}
}

static void		s_place_file_and_creat_pc(void)
{
	t_listd		*list_files;
	t_file		*file;
	size_t		list_size;
	size_t		id;

	list_size = ft_lstd_size(sgt_corewar()->files);
	list_files = sgt_corewar()->files;
	id = 1;
	while (list_files)
	{
		file = list_files->data;
		s_file_merge(file,
				sgt_corewar()->ram + (id - 1) * (MEM_SIZE / list_size), id);
		list_files = list_files->next;
		++id;
	}
}

static void			s_sort_files(void)
{
	size_t		len;
	t_listd		*list;
	t_vm_file	*tmp;
	t_vm_file	*file1;
	t_vm_file	*file2;

	len = ft_lstd_size(sgt_corewar()->files);
	while (len > 0)
	{
		list = sgt_corewar()->files;
		while (list->next)
		{
			file1 = list->data;
			file2 = list->next->data;
			if (file1->id > file2->id)
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
		sgt_corewar()->ram[i].id = 0;
		sgt_corewar()->ram[i].modified = false;
		sgt_corewar()->ram[i].live = false;
		++i;
	}
	s_sort_files();
	s_place_file();
}
