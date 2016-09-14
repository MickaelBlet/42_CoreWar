/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 09:22:40 by mblet             #+#    #+#             */
/*   Updated: 2016/09/12 15:01:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../includes/common_corewar.h"

# include <fcntl.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define USAGE		"./corewar [-dump nbr_cycles] [[-n number] file.cor]"

typedef struct	s_corewar
{
	t_listd		*players;
	t_op		op[17];
	size_t		nb_cycles;
	int			ram[MEM_SIZE];
}				t_corewar;

/*
** MAIN
*/
void			corewar(void);

/*
** SGT
*/
t_corewar		**sgt_addr_corewar(void);
t_corewar		*sgt_corewar(void);
t_op			op_tab(int index);

/*
** OP
*/

#endif
