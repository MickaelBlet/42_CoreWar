/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 03:45:35 by mblet             #+#    #+#             */
/*   Updated: 2016/09/28 16:24:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_error(int id, void *object)
{
	if (id == 0)
		ft_dprintf(STDERR_FILENO, ERR_OPEN_FILE, (char *)object);
	else if (id == 1)
		ft_dprintf(STDERR_FILENO, ERR_FILE_TOO_LARGE, (char *)object);
	else if (id == 2)
		ft_dprintf(STDERR_FILENO, ERR_FILE_NOT_VALID, (char *)object);
	else
		return ;
	exit(EXIT_FAILURE);
}

static void		s_read(t_file *file, int fd, char *file_name)
{
	int		index;
	int		ret_read;
	char	buff[BUFF_SIZE + 1];

	index = 0;
	while ((ret_read = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		if ((index + ret_read) > (int)(sizeof(file->data)))
			s_error(1, file_name);
		ft_memcpy(file->data + index, buff, ret_read);
		index += ret_read;
	}
	file->header = file_get_header(file->data);
	if (file->header->magic != COREWAR_EXEC_MAGIC)
		s_error(2, file_name);
}

t_vm_file		*file_read(char *file_name)
{
	int		fd;
	t_file	*file;

	if ((file = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		s_error(0, file_name);
	s_read(file, fd, file_name);
	return (file);
}
