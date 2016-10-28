/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 18:12:18 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 01:00:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

#include <errno.h>

static unsigned int		s_swap_int(unsigned int a)
{
	return ((a << 24) | \
			((a << 8) & 0x00ff0000) | \
			((a >> 8) & 0x0000ff00) | \
			((unsigned int)(a >> 24)));
}

static t_header			*s_file_get_header(void)
{
	t_header	*header;

	header = (t_header *)sgt_dasm()->file.data;
	header->magic = s_swap_int(header->magic);
	header->prog_size = s_swap_int(header->prog_size);
	return (header);
}

static t_bool			s_read(int fd, char *file_name)
{
	int		index;
	int		ret_read;
	char	buff[BUFF_SIZE + 1];

	index = 0;
	while ((ret_read = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		if ((index + ret_read) > (int)(sizeof(sgt_dasm()->file.data)))
		{
			ERROR("%s: %s", file_name, "File too large");
			return (false);
		}
		ft_memcpy(sgt_dasm()->file.data + index, buff, ret_read);
		index += ret_read;
	}
	if (index == 0)
	{
		ERROR("%s: %s", file_name, ft_strerror());
		return (false);
	}
	return (true);
}

void					file_read(char *file_name)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return ((void)ERROR("%s: %s", file_name, ft_strerror()));
	if (s_read(fd, file_name) == false)
		return ;
	close(fd);
	sgt_dasm()->file.header = s_file_get_header();
	if (sgt_dasm()->file.header->magic != COREWAR_EXEC_MAGIC)
		return ((void)ERROR("%s: %s", file_name, "bad file"));
	sgt_dasm()->file_name = file_name;
	sgt_dasm()->data = sgt_dasm()->file.data + sizeof(t_header);
	op_check();
}
