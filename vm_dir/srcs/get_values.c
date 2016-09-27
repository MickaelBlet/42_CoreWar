/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 10:39:04 by mblet             #+#    #+#             */
/*   Updated: 2016/09/27 19:24:27 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_reg_value(t_byte *b)
{
	DGL;
	return ((unsigned int)(b->data - 1));
}

int		get_dir_value(t_byte *b)
{
	int		ret;

	ret = 0;
	ret += b->data;
	ret *= 16;
	ret += (b + 1)->data;
	return (ret);
}

int		get_ind_value(t_byte *b)
{
	int		ret;

	ret = 0;
	ret += b->data;
	ret *= 16;
	ret += (b + 1)->data;
	ret *= 16;
	ret += (b + 2)->data;
	ret *= 16;
	ret += (b + 3)->data;
	return (ret);
}
