/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 02:41:34 by mblet             #+#    #+#             */
/*   Updated: 2016/09/18 05:11:41 by mblet            ###   ########.fr       */
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

t_header				*file_get_header(void *ptr)
{
	t_header	*header;

	header = (t_header *)ptr;
	header->magic = s_swap_int(header->magic);
	header->prog_size = s_swap_int(header->prog_size);
	return (header);
}
