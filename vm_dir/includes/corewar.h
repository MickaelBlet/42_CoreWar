/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 09:22:40 by mblet             #+#    #+#             */
/*   Updated: 2016/09/14 16:55:31 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../includes/common_corewar.h"

# include <fcntl.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define MSG_USAGE		"./corewar [-dump nbr_cycles] [[-n number] file.cor]"
# define ERR_OPEN_FILE			"corewar: Can't open file \"%s\".\n"
# define ERR_SAME_ID			"corewar: Same file id.\n"
# define ERR_FILE_TOO_LARGE		"corewar: File \"%s\" is too large.\n"
# define ERR_FILE_NOT_VALID		"corewar: File \"%s\" not valid.\n"
# define ERR_TOO_MANY_PLAYERS	"corewar: Too many players.\n"

typedef struct	s_player
{
	int			id;
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
	t_arg_type	*pc;
	t_arg_type	data[CHAMP_MAX_SIZE + 1];
	int			reg[REG_NUMBER];
}				t_player;

typedef struct	s_corewar
{
	size_t		nb_cycles;
	t_listd		*players;
	t_arg_type	ram[MEM_SIZE];
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

/*
** OP
*/
t_op			op_tab(int index);

#endif
