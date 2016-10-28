/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 18:11:18 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 00:28:59 by mblet            ###   ########.fr       */
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

# define COMMENT_CHAR_BASIC		';'
# define QUOTE_CHAR				'"'

# define ERR_CMD_SAME			"command is already declared"
# define ERR_CMD_NAME_NO_ARG	"need argument after command .name"
# define ERR_CMD_COM_NO_ARG		"need argument after command .comment"
# define ERR_CMD_NAME_NO_QUOTE	"need '\"' after command .name"
# define ERR_CMD_COM_NO_QUOTE	"need '\"' after command .comment"
# define ERR_CMD_NAME_EXTRA_ARG	"extra argument after command .name"
# define ERR_CMD_COM_EXTRA_ARG	"extra argument after command .comment"
# define ERR_CMD_EXTRA_ARG		"extra argument after unknown command"

# define WAR_CMD_UNKNOWN	"unknown command"

# define ERR_LAB_NAME		"bad syntax of label"
# define ERR_LAB_SAME		"label is already declared"
# define ERR_LAB_B_CHAR		"expected ':' before label"
# define ERR_LAB_A_CHAR		"expected ':' after label"

# define ERR_OP_UNKNOWN		"unknown operation"
# define ERR_OP_NO_ARG		"need argument after operation"
# define ERR_OP_SEP			"need ',' after argument"
# define ERR_OP_TOO_FEW		"too few arguments"
# define ERR_OP_TOO_MANY	"too many arguments"
# define ERR_OP_BAD_ARG		"bad argument"
# define ERR_OP_BAD_TYPE	"bad type"
# define ERR_OP_LAB_NOT_FOUND "label not found"

typedef struct		s_arg
{
	struct s_line	*line;
	int				column;
	int				index_cor;
	int				type;
	char			*data;
	int				code;
}					t_arg;

typedef struct		s_line
{
	int				index;
	int				index_cor;
	char			*data;
	t_op			op;
	int				nb_args;
	t_arg			args[MAX_ARGS_NUMBER];
}					t_line;

typedef struct		s_cor
{
	t_header		header;
	char			data[CHAMP_MAX_SIZE];
}					t_cor;

typedef struct		s_error
{
	int				line;
	int				column;
	char			*str;
}					t_error;

typedef struct		s_asm
{
	int				index_cor;
	t_cor			cor;
	char			*file_name;
	t_listd			*lines;
	t_listd			*commands;
	t_listd			*labels;
	t_listd			*errors;
	t_bool			error;
}					t_asm;

/*
** MAIN
*/
void				cor_asm(int argc, char **argv);

/*
** SINGLETON
*/
t_asm				**sgt_addr_asm(void);
t_asm				*sgt_asm(void);
t_op				op_tab(int index);

/*
** ERROR
*/
void				error_print(t_arg arg, const char *str);
void				error_print_sug(t_arg arg,
		const char *str, const char *sug);
void				error_list_print(void);
void				warning_print(t_arg arg, const char *str);

/*
** COR
*/
void				ini_cor(void);

/*
** FILE
*/
void				file_read(char *file_name);
void				file_write(void);
void				file_clean(void);

/*
** LINE
*/
t_line				*line_creat(int index, char *str);
void				line_scan(int column, t_line *line);
void				line_scan_op(t_line *line);
void				line_label_scan(int column, t_line *line);
void				line_check_command(int column, t_line *line);
void				line_check_label(int column, t_arg arg);
void				line_check_op(int column, t_arg arg);

/*
** COMMAND
*/
void				command_name(int column, t_arg arg);
void				command_comment(int column, t_arg arg);
t_bool				command_check_same(char *name);

/*
** LABEL
*/
void				label_add(t_arg arg);
t_bool				label_check_name(char *name);
t_bool				label_check_same(char *name);
int					label_get_addr(int index, char *name);

/*
** OP
*/
t_bool				op_check_name(char *name);
t_op				op_get_from_name(char *name);
int					op_get_type(t_op op, char *str);
void				op_to_cor(t_line *line);
void				op_arg_to_cor(t_line *line, t_arg *arg);

/*
** WRITE
*/
void				write_file(void);

void				dump(void);

#endif
