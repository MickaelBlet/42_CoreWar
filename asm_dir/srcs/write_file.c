/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 02:35:16 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 03:13:53 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	s_swap(int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | ((val >> 16) & 0xFFFF);
}

void		write_file(void)
{
	char	new_name[1024];
	int		fd;

	if (sgt_asm()->error == true)
		return ;
	if (ft_strrchr(sgt_asm()->file_name, '.') != NULL)
		ft_sprintf(new_name, "%.*s.cor2",
				ft_strrchr(sgt_asm()->file_name, '.') - sgt_asm()->file_name,
				sgt_asm()->file_name);
	else
		ft_sprintf(new_name, "%s.cor2", sgt_asm()->file_name);
	if ((fd = open(new_name, O_WRONLY | O_CREAT, 0644)) == -1)
		return ((void)ERROR("%s: %s", sgt_asm()->file_name, ft_strerror()));
	sgt_asm()->cor.header.magic = s_swap(COREWAR_EXEC_MAGIC);
	sgt_asm()->cor.header.prog_size = s_swap(sgt_asm()->index_cor);
	write(fd, (char *)(&sgt_asm()->cor.header), sizeof(t_header));
	write(fd, (char *)sgt_asm()->cor.data, sgt_asm()->index_cor);
	ft_printf("Writing output program to %s\n", new_name);
}
