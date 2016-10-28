/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 17:56:46 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 00:19:41 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DASM_H
# define DASM_H

# include "../../includes/common_corewar.h"

# include <fcntl.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define BIN_NAME	"./dasm"

# define USAGE	"Usage: " BIN_NAME " [cor_file.cor]"

# define __ER0		STDERR_FILENO, "{bold}" BIN_NAME ": {red}error: {white}"
# define ERROR(f, ...)	ft_dprintf(__ER0 f "{reset}\n", ##__VA_ARGS__)

typedef struct		s_arg
{
	int				type;
	int				value;
	t_bool			label;
	int				id_label;
}					t_arg;

typedef struct		s_line
{
	int				index_cor;
	t_op			op;
	t_arg			arg[MAX_ARGS_NUMBER];
	t_bool			has_label;
	char			str[1024];
	int				length_str;
}					t_line;

typedef struct		s_file
{
	t_header		*header;
	char			data[CHAMP_MAX_SIZE + sizeof(t_header)];
}					t_file;

typedef struct		s_dasm
{
	unsigned int	index_cor;
	char			*file_name;
	t_file			file;
	char			*data;
	t_listd			*lines;
}					t_dasm;

/*
** MAIN
*/
void				dasm(int argc, char **argv);

/*
** SGT
*/
t_dasm				**sgt_addr_dasm(void);
t_dasm				*sgt_dasm(void);

/*
** OP
*/
t_op				op_tab(int index);
void				byte_code_to_type(int (*t)[4], unsigned char b);
int					get_value_from_type(size_t index, int type, int has_idx);
void				op_check(void);

/*
** FILE
*/
void				file_read(char *file_name);
void				file_write(void);

/*
** LINE
*/
t_line				*line_creat(int index_cor, t_op op);
void				line_set_label(void);
void				line_print(void);

#endif
