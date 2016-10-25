/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 21:27:40 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 00:05:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#include <errno.h>

static t_bool	s_line(t_listd **list, int index, char *line_str)
{
	t_line	*line;

	if ((line = line_creat(index, line_str)) == NULL)
		return (false);
	ft_lstd_push_after(list, line);
	if (*list == NULL)
		return (false);
	if ((*list)->next == NULL)
		sgt_asm()->file.lines = *list;
	else
		*list = (*list)->next;
	return (true);
}

static t_bool	s_file_read_line(int fd)
{
	int			index;
	int			ret_read;
	char		*line_str;
	t_listd		*list;

	index = 0;
	line_str = NULL;
	list = NULL;
	while ((ret_read = ft_get_next_line(fd, &line_str)) > 0)
	{
		if (s_line(&list, index, line_str) == false)
			return (false);
		if (++index > 50000)
		{
			errno = EFBIG;
			return (false);
		}
	}
	if (index == 0)
		return (false);
	return (true);
}

static void		s_test(t_line *line)
{
	ft_printf("%5i: %s\n", line->index, line->data);
}

void			file_read(char *file_name)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return ((void)ERROR("%s: %s", file_name, ft_strerror()));
	sgt_asm()->file.name = file_name;
	sgt_asm()->file.lines = NULL;
	sgt_asm()->file.labels = NULL;
	if (s_file_read_line(fd) == false)
		return ((void)ERROR("%s: %s", file_name, ft_strerror()));
	ft_lstd_map(&sgt_asm()->file.lines, &s_test);
}
