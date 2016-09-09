/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 09:22:40 by mblet             #+#    #+#             */
/*   Updated: 2016/09/08 15:46:17 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define USAGE		"./corewar [-dump nbr_cycles] [[-n number] file.cor]"

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

/*
** ...
*/

typedef char		t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

/*
** ...
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_op
{
	char			*name;
	int				nb_args;
	int				type_args[4];
	int				op_code;
	int				nb_cycles;
	char			*description;
	int				has_pcode;
	int				has_idx;
}					t_op;

typedef struct		s_corewar
{
	t_listd			*players;
	t_op			op[17];
	size_t			nb_cycles;
	int				ram[MEM_SIZE];
}					t_corewar;

/*
** MAIN
*/
void				corewar(void);

/*
** SGT
*/
t_corewar			**sgt_addr_corewar(void);
t_corewar			*sgt_corewar(void);

/*
** OP
*/

#endif
