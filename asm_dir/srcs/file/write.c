/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 23:51:22 by mblet             #+#    #+#             */
/*   Updated: 2016/11/16 15:05:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		s_swap(int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | ((val >> 16) & 0xFFFF);
}

static void		s_set_new_name(char **ret, char *file_name)
{
	if (ft_strrchr(file_name, '.') != NULL
		&& ft_strrchr(file_name, '.')[1] != '/')
	{
		ft_asprintf(ret, "%.*s.cor",
				ft_strrchr(file_name, '.') - file_name,
				file_name);
	}
	else
	{
		ft_asprintf(ret, "%s.cor",
				file_name);
	}
}

void			file_write(void)
{
	int		fd;
	char	*new;

	if (sgt_asm()->index_cor == 0
		&& sgt_asm()->commands == NULL
		&& sgt_asm()->labels == NULL)
		return ((void)ERROR("%s: %s", sgt_asm()->file_name, "bad file"));
	if (sgt_asm()->index_cor > CHAMP_MAX_SIZE)
		return ((void)ERROR("%s: %s", sgt_asm()->file_name, "champion size"));
	new = NULL;
	s_set_new_name(&new, sgt_asm()->file_name);
	if ((fd = open(new, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		ERROR("%s: %s", new, ft_strerror());
		return (ft_strdel(&new));
	}
	sgt_asm()->cor.header.magic = s_swap(COREWAR_EXEC_MAGIC);
	sgt_asm()->cor.header.prog_size = s_swap(sgt_asm()->index_cor);
	write(fd, (char *)(&sgt_asm()->cor.header), sizeof(t_header));
	write(fd, (char *)sgt_asm()->cor.data, sgt_asm()->index_cor);
	ft_printf("Writing output program to %s\n", new);
	ft_strdel(&new);
}
