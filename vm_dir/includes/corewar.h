/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 09:22:40 by mblet             #+#    #+#             */
/*   Updated: 2016/10/07 15:03:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../includes/common_corewar.h"

# include <fcntl.h>
# include <libft.h>
# include <libxft.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define MSG_USAGE		"./corewar [-dump nbr_cycles] [[-n number] file.cor]"

# define ERR_OPEN_FILE			"corewar: Can't open file \"%s\".\n"
# define ERR_SAME_ID			"corewar: Same file id.\n"
# define ERR_FILE_TOO_LARGE		"corewar: File \"%s\" is too large.\n"
# define ERR_FILE_NOT_VALID		"corewar: File \"%s\" not valid.\n"
# define ERR_TOO_MANY_PLAYERS	"corewar: Too many players.\n"

typedef struct		s_byte
{
	unsigned char	data;
	int				color_id;
	t_bool			modified;
	t_bool			live;
}					t_byte;

typedef struct		s_process
{
	int				id;
	size_t			pc;
	int				reg[REG_NUMBER];
	int				live;
	int				carry;
	int				op_cycle;
	int				color_id;
}					t_process;

typedef struct		s_file
{
	int				id;
	t_header		*header;
	char			data[CHAMP_MAX_SIZE + sizeof(t_header)];
}					t_file;

typedef struct		s_corewar
{
	size_t			nbr_cycles;
	size_t			nbr_live;
	t_byte			ram[MEM_SIZE];
	t_listd			*files;
	t_listd			*players;
}					t_corewar;

typedef void		(*t_func_op)(t_process *, int *val);

/*
** MAIN
*/
void				corewar(int argc, char **argv);

/*
** SGT
*/
t_corewar			**sgt_addr_corewar(void);
t_corewar			*sgt_corewar(void);

/*
** OPTION
*/
t_bool				vm_check_option(int argc, char **argv);

/*
** FILE
*/
void				vm_check_file(int *i, char **argv);
t_vm_file			*file_read(char *file_name);
t_header			*file_get_header(void *ptr);

/*
** PROCESS
*/
t_process			*process_creat(size_t index, int id, int color_id);
t_process			*process_fork(t_process *process, size_t index);

/*
** OP
*/
void				check_op(t_process *process);
void				byte_code_to_type(int (*t)[4], unsigned char b);
t_op				op_tab(int index);
t_func_op			func_tab(int index);
void				op_live(t_process *process);
void				op_ld(t_process *process);
void				op_st(t_process *process);
void				op_add(t_process *process);
void				op_sub(t_process *process);
void				op_and(t_process *process);
void				op_or(t_process *process);
void				op_xor(t_process *process);
void				op_zjmp(t_process *process);
void				op_ldi(t_process *process);
void				op_sti(t_process *process);
void				op_fork(t_process *process);
void				op_lld(t_process *process);
void				op_lldi(t_process *process);
void				op_lfork(t_process *process);
void				op_aff(t_process *process);

/*
** GET
*/
int					get_reg_value(t_byte *b);
int					get_dir_value(t_byte *b);
int					get_ind_value(t_byte *b);
int					get_reg_value_from_index(size_t index);
int					get_dir_value_from_index(size_t index);
int					get_ind_value_from_index(size_t index);

/*
** SET
*/
void				set_1byte_value_to_index(t_process *process, size_t index,
		unsigned char value);
void				set_2byte_value_to_index(t_process *process, size_t index,
		unsigned short value);
void				set_4byte_value_to_index(t_process *process, size_t index,
		unsigned int value);

/*
** PLAYER
*/
t_player			*player_creat(int id, char *file_name);
t_header			*player_get_header(void *ptr);

/*
** #############################################################################
**                                     MLX
** #############################################################################
*/
# define VM_WIN_WIDTH		1600
# define VM_WIN_HEIGHT		1200
# define VM_FONT_PATH		"./resources/font/11.xpm"

# define VM_COLOR_PLAYER1	0xA00000
# define VM_COLOR_PLAYER2	0x00A000
# define VM_COLOR_PLAYER3	0xA0A000
# define VM_COLOR_PLAYER4	0x0000A0
# define VM_COLOR_PLAYER5	0xA000A0
# define VM_COLOR_PLAYER6	0x00A0A0
# define VM_COLOR_BOLD		0x505050

typedef struct		s_vm_mlx
{
	void			*mlx;
	void			*win;
	t_libx_img		*img_main;
	t_libx_img		*img_font;
	t_libx_img		*img_ram;
}					t_vm_mlx;

/*
** ...
*/
t_bool				vm_mlx_init(void);
int					vm_hook_key(int key, t_vm_mlx *mlx);
void				vm_press_key_esc(t_vm_mlx *mlx);
void				vm_mlx_print(void);
int					vm_mlx_loop_hook(void *mlx);

/*
** SGT
*/
t_vm_mlx			**sgt_addr_mlx(void);
t_vm_mlx			*sgt_mlx(void);

#endif
