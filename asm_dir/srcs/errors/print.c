/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 21:53:54 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 02:57:02 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_print(t_file *file, char *str_error,
		int line, int column)
{
	ft_printf("{bold}%s/%s:%lu:%lu: {red}error:{reset} {bold}%s{reset}",
			file->path, file->name, line, column, str_error);
}
