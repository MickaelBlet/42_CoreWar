/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 22:47:26 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 22:50:37 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_file	*file_creat(char *file_name)
{
	t_file	*file;

	if ((file = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	file->name = file_name;
	file->lines = NULL;
	return (file);
}
