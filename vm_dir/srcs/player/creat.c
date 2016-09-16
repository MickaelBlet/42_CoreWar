/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:23:37 by mblet             #+#    #+#             */
/*   Updated: 2016/09/16 16:10:23 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned int		s_swap_int(unsigned int a)
{
	return ((a << 24) | \
			((a << 8) & 0x00ff0000) | \
			((a >> 8) & 0x0000ff00) | \
			((unsigned int)(a >> 24)));
}

static void				s_id_free(int id, t_listd *player_list)
{
	t_player	*player;

	while (player_list)
	{
		player = player_list->data;
		if (player->id == id)
		{
			ft_dprintf(STDERR_FILENO, ERR_SAME_ID);
			exit(EXIT_FAILURE);
		}
		player_list = player_list->next;
	}
}

static int				s_find_id(t_listd *player_list)
{
	int			id;
	int			index;
	t_listd		*tmp_list;
	t_player	*player;

	id = -1;
	index = 1;
	while (index <= MAX_PLAYERS)
	{
		tmp_list = player_list;
		while (tmp_list)
		{
			player = tmp_list->data;
			if (player->id == index)
				break ;
			else
				tmp_list = tmp_list->next;
		}
		if (tmp_list == NULL)
			return (index);
		++index;
	}
	ft_dprintf(STDERR_FILENO, ERR_TOO_MANY_PLAYERS);
	exit(EXIT_FAILURE);
	return (-1);
}

static void				s_player_read_file(t_player *player, char *file_name,
		int fd)
{
	char		buff[BUFF_SIZE + 1];
	int			ret_read;
	int			index;
	t_header	*header;

	index = 0;
	while ((ret_read = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		if ((index + ret_read) > (int)(CHAMP_MAX_SIZE + sizeof(t_header)))
		{
			ft_dprintf(STDERR_FILENO, ERR_FILE_TOO_LARGE, file_name);
			exit(EXIT_FAILURE);
		}
		ft_memcpy(player->data + index, buff, ret_read);
		index += ret_read;
	}
	header = (t_header *)player->data;
	if (s_swap_int(header->magic) != COREWAR_EXEC_MAGIC)
	{
		ft_dprintf(STDERR_FILENO, ERR_FILE_NOT_VALID, file_name);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(player->name, header->prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(player->comment, header->comment, COMMENT_LENGTH + 1);
	player->prog_size = s_swap_int(header->prog_size);
}

t_player				*player_creat(int id, char *file_name)
{
	int			fd;
	t_player	*player;

	if ((player = (t_player *)malloc(sizeof(t_player))) == NULL)
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_dprintf(STDERR_FILENO, ERR_OPEN_FILE, file_name);
		exit(EXIT_FAILURE);
	}
	if (id == -1)
		id = s_find_id(sgt_corewar()->players);
	else
		s_id_free(id, sgt_corewar()->players);
	player->id = id;
	ft_bzero(player->data, CHAMP_MAX_SIZE + sizeof(t_header));
	s_player_read_file(player, file_name, fd);
	ft_bzero(player->reg, REG_NUMBER * sizeof(int));
	player->reg[0] = id;
	return (player);
}
