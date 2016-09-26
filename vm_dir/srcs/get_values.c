/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 10:39:04 by mblet             #+#    #+#             */
/*   Updated: 2016/09/26 16:45:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	get_reg_value(t_byte *b)
{
	return ((unsigned int)(b->data - 1));
}

unsigned int	get_dir_value(t_byte *b)
{
	unsigned char	v[2];

	v[0] = b->data;
	v[1] = (b + 1)->data;
	DG("%2x%2x", v[0], v[1]);
	//test
	return (0);
}

unsigned int	get_ind_value(t_byte *b)
{
	unsigned char	v[4];

	v[0] = b->data;
	v[1] = (b + 1)->data;
	v[2] = (b + 2)->data;
	v[3] = (b + 3)->data;
	DG("%2x%2x%2x%2x", v[0], v[1], v[2], v[3]);
	//test
	return (0);
}
