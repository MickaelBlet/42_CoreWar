/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 03:45:35 by mblet             #+#    #+#             */
/*   Updated: 2017/01/03 19:22:22 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include <errno.h>

static void		s_error(int id, void *object)
{
	if (id == 0 && ft_strerror() != NULL)
		ERROR("\"%s\": %s", (char *)object, ft_strerror());
	else if (id == 1)
		ERROR("\"%s\": %s", (char *)object, ft_strerr(EFBIG));
	else if (id == 2 && ft_strerror() != NULL)
		ERROR("\"%s\": %s", (char *)object, ft_strerror());
	else
		ERROR("\"%s\": %s", (char *)object, ERR_FILE_NOT_VALID);
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
	if (file->header->prog_size > CHAMP_MAX_SIZE)
		s_error(3, file_name);
}

t_file			*file_read(char *file_name)
{
	int		fd;
	t_file	*file;

	if ((file = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		s_error(0, file_name);
	s_read(file, fd, file_name);
	close(fd);
	return (file);
}
