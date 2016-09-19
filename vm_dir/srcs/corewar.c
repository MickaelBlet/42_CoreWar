/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:04:28 by mblet             #+#    #+#             */
/*   Updated: 2016/09/19 17:53:10 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			s_fill_player_ram(t_vm_file *file, t_byte *b)
{
	size_t		i;

	i = 0;
	while (i < file->header->prog_size)
	{
		b->data = file->data[sizeof(t_header) + i];
		b->id = file->id;
		b->last_id = file->id;
		++b;
		++i;
	}
}

static t_player		*s_creat_player(int index, int id, t_byte *pc)
{
	t_player	*player;
	int			i;

	if ((player = (t_player *)malloc(sizeof(t_player))) == NULL)
		return (NULL);
	player->index = index;
	player->id = id;
	player->pc = pc;
	i = 0;
	while (i < REG_NUMBER)
	{
		player->reg[i] = 0;
		++i;
	}
	player->reg[0] = id;
	player->live = 0;
	player->carry = 0;
	return (player);
}

static void			s_place_player(void)
{
	t_listd		*list_files;
	t_vm_file	*vm_file;
	size_t		player_size;
	size_t		index;

	player_size = ft_lstd_size(sgt_corewar()->files);
	list_files = sgt_corewar()->files;
	index = 1;
	while (list_files)
	{
		vm_file = list_files->data;
		ft_lstd_push_front(&sgt_corewar()->players,
				s_creat_player(index, vm_file->id,
					sgt_corewar()->ram + (index - 1) *
					(MEM_SIZE / player_size)));
		s_fill_player_ram(vm_file,
				sgt_corewar()->ram + (index - 1) *
					(MEM_SIZE / player_size));
		list_files = list_files->next;
		++index;
	}
}

static void			s_ini_ram(void)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		sgt_corewar()->ram[i].data = 0;
		sgt_corewar()->ram[i].id = 0;
		sgt_corewar()->ram[i].last_id = 0;
		++i;
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

void				corewar(int argc, char **argv)
{
	if (vm_check_option(argc, argv) == false)
	{
		ft_printf("Usage: %s\n", MSG_USAGE);
		exit(EXIT_FAILURE);
	}
	s_sort_files();
	s_ini_ram();
	s_place_player();
	if (vm_mlx_init() == false)
	{
		ft_dprintf(STDERR_FILENO, "init mlx.\n");
		exit(EXIT_FAILURE);
	}
	vm_mlx_print();
	mlx_loop(sgt_mlx()->mlx);
}
