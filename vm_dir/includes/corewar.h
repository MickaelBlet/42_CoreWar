/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 09:22:40 by mblet             #+#    #+#             */
/*   Updated: 2016/11/07 00:00:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../includes/common_corewar.h"

# include <fcntl.h>
# include <libft.h>
# include <libxft.h>
# include <mlx.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

# define BIN_NAME		"./corewar"

# define __MSG1			" [-g] [-d nbr_cycles] "
# define __MSG2			"[--aff --lives --cycles --ops --deaths --moves] "
# define __MSG3			"[[-n number] file.cor]"
# define MSG_USAGE		BIN_NAME __MSG1 __MSG2 __MSG3

# define __ER0		STDERR_FILENO, "{bold}" BIN_NAME ": {red}error: {white}"
# define ERROR(f, ...)	ft_dprintf(__ER0 f "{reset}\n", ##__VA_ARGS__)

# define ERR_FILE_NOT_VALID		"File not valid"
# define ERR_FILE_SAME_ID		"Same file id \"%i\""
# define ERR_FILE_FORMAT_ID		"Format id \"%s\""
# define ERR_DUMP_FORMAT		"Format dump \"%s\""
# define ERR_TOO_MANY_PLAYERS	"Too many players"

# define ERR_INIT_MLX			"Init mlx"

typedef struct			s_byte
{
	unsigned char		data;
	int					color_id;
	int					modified_cycle;
	int					live;
}						t_byte;

typedef struct			s_process
{
	size_t				uid;
	int					id;
	size_t				pc;
	int					live;
	int					reg[REG_NUMBER];
	int					carry;
	t_bool				in_action;
	t_op				op;
	int					op_cycle;
	int					color_id;
}						t_process;

typedef struct			s_player
{
	int					id;
	int					color_id;
	size_t				live;
	long				last_live;
	char				*name;
	char				*description;
}						t_player;

typedef struct			s_file
{
	int					id;
	t_header			*header;
	char				data[CHAMP_MAX_SIZE + sizeof(t_header)];
}						t_file;

typedef struct			s_verbose
{
	t_bool				aff;
	t_bool				live;
	t_bool				cycle;
	t_bool				op;
	t_bool				death;
	t_bool				move;
}						t_verbose;

typedef struct			s_option
{
	t_verbose			verbose;
	int					dump;
	t_bool				graphic;
}						t_option;

typedef struct			s_corewar
{
	long				cycle;
	long				cycle_to_die;
	size_t				cycle_check;
	long				last_cycle_check;
	int					id_last_live;
	t_byte				ram[MEM_SIZE];
	t_listd				*files;
	t_listd				*players;
	t_listd				*process;
	pthread_t			thread;
	pthread_mutex_t		mutex;
	pthread_mutex_t		mutex_process;
	size_t				nb_process;
	size_t				nb_cycle_per_second;
	t_option			option;
	t_bool				run;
}						t_corewar;

typedef void			(*t_func_op)(t_process *process, int type[4],
		int arg[4]);

/*
** MAIN
*/
void					corewar(int argc, char **argv);

/*
** SGT
*/
t_corewar				**sgt_addr_corewar(void);
t_corewar				*sgt_corewar(void);

/*
** OPTION
*/
void					option(int argc, char **argv);
void					usage(void);

/*
** FILE
*/
void					file_check(int *i, char **argv);
t_file					*file_read(char *file_name);
t_header				*file_get_header(void *ptr);

/*
** PLAYER
*/
t_player				*player_creat(t_file *file, int color_id);

/*
** PROCESS
*/
t_process				*process_creat(size_t index, int id, int color_id);
t_process				*process_fork(t_process *process, size_t index);
void					process_action(t_process *process);
void					process_check_live(void);

/*
** OP
*/
void					byte_code_to_type(int (*t)[4], unsigned char b);
t_bool					check_type_args(t_op op, int type[4], int arg[4]);
t_op					op_tab(int index);
t_func_op				func_tab(int index);
void					op_live(t_process *process, int type[4], int arg[4]);
void					op_ld(t_process *process, int type[4], int arg[4]);
void					op_st(t_process *process, int type[4], int arg[4]);
void					op_add(t_process *process, int type[4], int arg[4]);
void					op_sub(t_process *process, int type[4], int arg[4]);
void					op_and(t_process *process, int type[4], int arg[4]);
void					op_or(t_process *process, int type[4], int arg[4]);
void					op_xor(t_process *process, int type[4], int arg[4]);
void					op_zjmp(t_process *process, int type[4], int arg[4]);
void					op_ldi(t_process *process, int type[4], int arg[4]);
void					op_sti(t_process *process, int type[4], int arg[4]);
void					op_fork(t_process *process, int type[4], int arg[4]);
void					op_lld(t_process *process, int type[4], int arg[4]);
void					op_lldi(t_process *process, int type[4], int arg[4]);
void					op_lfork(t_process *process, int type[4], int arg[4]);
void					op_aff(t_process *process, int type[4], int arg[4]);

/*
** RAM
*/
void					ini_ram(void);

/*
** GET
*/
int						get_value_from_type(size_t index, int type,
		int has_idx);
int						get_reg_value(size_t index);
int						get_dir_value(size_t index);
int						get_ind_value(size_t index);

/*
** SET
*/
void					set_1byte_value(t_process *process, int index,
		unsigned char value);
void					set_2byte_value(t_process *process, int index,
		unsigned short value);
void					set_4byte_value(t_process *process, int index,
		unsigned int value);

/*
** THREAD
*/
void					*thread_vm(void *e);
void					thread_launch(void);

/*
** CYCLE
*/
void					cycle(void);

/*
** DUMP
*/
void					dump(void);

/*
** VERBOSE
*/
void					verbose_live(int id, char *name);
void					verbose_cycle(void);
void					verbose_cycle_to_die(void);
void					verbose_op(t_process *process, int type[4], int arg[4]);
void					verbose_death(t_process *process);
void					verbose_move(t_process *process, int jump);
t_func_op				func_verbose_tab(int index);
void					verbose_op_live(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_ld(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_st(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_add(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_sub(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_and(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_or(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_xor(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_zjmp(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_ldi(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_sti(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_fork(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_lld(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_lldi(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_lfork(t_process *process,
		int type[4], int arg[4]);
void					verbose_op_aff(t_process *process,
		int type[4], int arg[4]);

/*
** WIN
*/
void					win(void);

/*
** #############################################################################
**                                     MLX
** #############################################################################
*/
# define VM_WIN_WIDTH				1684
# define VM_WIN_HEIGHT				1034

# define VM_PATH_FONT				"./resources/font/11.xpm"

# define VM_COLOR_BOLD				0x505050

# define VM_MEMORY_D_HEIGHT			5
# define VM_MEMORY_NB_BYTE_LINE		64
# define VM_MEMORY_BYTE_WIDTH		20
# define VM_MEMORY_BYTE_HEIGHT		16

# define VM_TOOLTIP_WIDTH			180
# define VM_TOOLTIP_HEIGHT			63
# define VM_TOOLTIP_MINI_WIDTH		50
# define VM_TOOLTIP_MINI_HEIGHT		20

# define VM_INFO_WIDTH				400

typedef struct			s_mouse
{
	int					x;
	int					y;
}						t_mouse;

typedef struct			s_vm_mlx
{
	void				*mlx;
	void				*win;
	t_libx_img			*img_font;
	t_libx_img			*img_memory;
	t_libx_img			*img_info;
	unsigned char		*background_memory;
	unsigned char		*background_info;
	pthread_t			thread_memory;
	pthread_t			thread_info;
	pthread_mutex_t		mutex_memory;
	pthread_mutex_t		mutex_info;
	pthread_mutex_t		mutex_key;
	int					color[19];
	t_mouse				mouse;
	t_bool				pause;
}						t_vm_mlx;

/*
** INI
*/
void					vm_mlx_init(void);
void					vm_mlx_launch(void);

/*
** HOOK
*/
int						vm_hook_key(int key, t_vm_mlx *mlx);

/*
** KEYS
*/
void					vm_press_key_esc(t_vm_mlx *mlx);
void					vm_press_key_s(t_vm_mlx *mlx);
void					vm_press_key_sub(t_vm_mlx *mlx);
void					vm_press_key_add(t_vm_mlx *mlx);
void					vm_press_key_0(t_vm_mlx *mlx);
void					vm_press_key_9(t_vm_mlx *mlx);
void					vm_press_key_space(t_vm_mlx *mlx);

/*
** MOUSE
*/
int						vm_mlx_mouse_motion(int x, int y, t_vm_mlx *mlx);
void					byte_position_mouse(void);
char					*vm_mlx_get_info_byte(t_op op, int pc);

/*
** DRAW
*/
void					vm_mlx_draw_background_memory(void);
void					vm_mlx_draw_background_info(void);
void					vm_mlx_draw_memory(void);
void					vm_mlx_draw_info(void);
void					vm_mlx_draw_rect(t_libx_img *img, int xy[2], int wh[2],
		int color);
void					vm_mlx_draw_fill_transparent_rect(t_libx_img *img,
		int xy[2], int wh[2]);
void					vm_mlx_draw_pause(void);
void					vm_mlx_draw_tooltip(int pc);
void					vm_mlx_get_position_memory_from_pc(int pc, int *x,
		int *y);

/*
** LOOP
*/
int						vm_mlx_loop_hook(t_vm_mlx *mlx);

/*
** THREAD
*/
void					*vm_mlx_thread_memory(void *e);
void					*vm_mlx_thread_info(void *e);

/*
** SGT
*/
t_vm_mlx				**sgt_addr_mlx(void);
t_vm_mlx				*sgt_mlx(void);

#endif
