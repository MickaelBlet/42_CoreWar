/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 18:11:18 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 03:22:04 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../includes/common_corewar.h"

# include <fcntl.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define BIN_NAME	"./asm"

# define USAGE	"Usage: " BIN_NAME " [source_file.s]"

# define __ER0		STDERR_FILENO, "{bold}" BIN_NAME ": {red}error: {white}"
# define ERROR(f, ...)	ft_dprintf(__ER0 f "{reset}\n", ##__VA_ARGS__)

typedef struct	s_label
{
	int			index;
	char		*name;
}				t_label;

typedef struct	s_arg
{
	int			type;
	int			column;
	char		*data;
}				t_arg;

typedef struct	s_line
{
	int			index;
	char		*data;
	t_arg		op;
	t_arg		args[MAX_ARGS_NUMBER];
	char		code[32];
	size_t		len_code;
}				t_line;

typedef struct	s_cor
{
	t_header	header;
	char		*data;
}				t_cor;

typedef struct	s_file
{
	char		*name;
	t_listd		*lines;
	t_listd		*labels;
	t_cor		cor;
}				t_file;

typedef struct	s_asm
{
	t_file		file;
}				t_asm;

/*
** MAIN
*/
void			cor_asm(int argc, char **argv);

/*
** SINGLETON
*/
t_asm			**sgt_addr_asm(void);
t_asm			*sgt_asm(void);

/*
** ERROR
*/
void			error_print(t_file *file, char *str_error, int line,
		int column);

/*
** FILE
*/
void			file_read(char *file_name);
t_file			*file_creat(char *file_name);
void			file_clean(void);

/*
** LINE
*/
t_line			*line_creat(int index, char *str);

/*
** LABEL
*/
t_label			*label_creat(int index, char *name);
t_bool			label_check_name(char *name);
t_bool			label_check_same(char *name);
int				label_get_addr(int index, char *name);

#endif
