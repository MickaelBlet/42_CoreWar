/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 00:10:12 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 00:21:41 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void		s_print_lines_in_file(int fd)
{
	t_listd		*list;
	t_line		*line;

	list = sgt_dasm()->lines;
	while (list)
	{
		line = list->data;
		write(fd, line->str, line->length_str);
		list = list->next;
	}
}

static void		s_set_new_name(char **ret, char *file_name)
{
	if (ft_strrchr(file_name, '.') != NULL
		&& ft_strrchr(file_name, '.')[1] != '/')
	{
		ft_asprintf(ret, "%.*s_dasm.s",
				ft_strrchr(file_name, '.') - file_name,
				file_name);
	}
	else
	{
		ft_asprintf(ret, "%s_dasm.s",
				file_name);
	}
}

void			file_write(void)
{
	int		fd;
	char	*new;

	new = NULL;
	s_set_new_name(&new, sgt_dasm()->file_name);
	if ((fd = open(new, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		ERROR("%s: %s", new, ft_strerror());
		return (ft_strdel(&new));
	}
	ft_dprintf(fd, "%-12s\"%s\"\n", ".name",
			sgt_dasm()->file.header->prog_name);
	ft_dprintf(fd, "%-12s\"%s\"\n\n", ".comment",
			sgt_dasm()->file.header->comment);
	s_print_lines_in_file(fd);
	ft_printf("Writing output source to %s\n", new);
	ft_strdel(&new);
}
